#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "Ball.h"

static constexpr float SPEED = 1.0f;
static constexpr float MAX_SPEED = 40.0f;
static constexpr float MIN_SPEED = 0.0f;

Ball::Ball()
    :CharaObjBase(ObjTag.BALL)
    , moveVel(VGet(1,0,0))
{
    //モデル読み込み
    objHandle = AssetManager::ModelInstance()->GetHandle(modelData.GetString());
    objScale = VGet(0.08f, 0.08f, 0.08f);
    objDir = VGet(-1, 0, -1);
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale),rotateZMat), MGetTranslate(objPos)));

    //移動速度は走る速度
    moveSpeed = MIN_SPEED;

    //当たり判定はカプセル型
    capsule = new Capsule(VAdd(objPos, VGet(0, 6, 0)), VAdd(objPos, VGet(0, 30, 0)), 7.0f);
    CollisionManager::AddCol(this, capsule);
}

Ball::~Ball()
{
    //処理なし
}

void Ball::Update(const float deltaTime)
{
    a += deltaTime;

    //キャラ移動
    MoveChara(deltaTime);

    //座標更新
    CalcObjPos();

    //行列でモデルの動作
    objPos.y = capsule->GetRadius();
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), RotateVel()), MGetTranslate(objPos)));
}

void Ball::MoveChara(const float deltaTime)
{
    //停止中にする
    isMove = false;

    //キー入力による移動量
    MoveByKey(KEY_INPUT_W, VGet(1.0f,0,0), deltaTime);
    MoveByKey(KEY_INPUT_S, VGet(-1.0f,0,0), deltaTime);
    MoveByKey(KEY_INPUT_A, VGet(0,0,1.0f), deltaTime);
    MoveByKey(KEY_INPUT_D, VGet(0,0,-1.0f), deltaTime);
    moveVel = VNorm(moveVel);
    moveVel.y = 0;

    if (isMove)
    {
        //座標・方向の算出
        moveSpeed += SPEED;
        if (moveSpeed > MAX_SPEED)
        {
            moveSpeed = MAX_SPEED;
        }
    }
    else
    {
        moveSpeed *= 0.9f;
        if (moveSpeed < MIN_SPEED)
        {
            moveSpeed = MIN_SPEED;
        }
    }
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));

}

void Ball::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //キーが入力されていたら移動時の実行
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel =VAdd(moveVel, dir);

        //動作中にする
        isMove = true;
    }
}

void Ball::OnCollisionEnter(ObjBase* colObj)
{
    //当たり判定処理
    for (auto& obj : CollisionManager::GetCol(colObj))
    {
        if (obj->GetColTag() == ColTag.MODEL)
        {
            if (capsule->OnCollisionWithMesh(obj->GetColModel()))
            {
                objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh());
                moveVel = VScale(moveVel, -1);
                MV1CollResultPolyDimTerminate(capsule->GetColInfoDim());
            }
        }
    }

    //座標更新
    CalcObjPos();
    capsule->Update(objPos);

    //行列でモデルの動作
    //MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Ball::Draw()
{
    //モデル描画
    MV1DrawModel(objHandle);

#ifdef _DEBUG
    //当たり判定描画
    capsule->DrawCapsule();

    //当たったポリゴン
    for (int i = 0; i < colInfo.HitNum; i++)
    {
        DrawTriangle3D(
            colInfo.Dim[i].Position[0],
            colInfo.Dim[i].Position[1],
            colInfo.Dim[i].Position[2], GetColor(0, 255, 255), TRUE);
    }

    DrawFormatString(20, 800, GetColor(255, 255, 255), "%f,%f,%f", moveVel.x, moveVel.y, moveVel.z);
#endif // _DEBUG
}

MATRIX Ball::RotateVel()
{
    if (static_cast<int>(abs(moveVel.z)) > 0)
    {
        RotateXAxis(moveVel, VSize(moveVel) * moveSpeed / 8.0f);
        if (objDir.z>0)
        {
            return rotateXMat;
        }
        else
        {
            return MInverse(rotateXMat);
        }
    }
    if (static_cast<int>(abs(moveVel.x)) > 0)
    {
        RotateZAxis(moveVel, VSize(moveVel) * moveSpeed / 8.0f);
        return rotateZMat;
    }
    return MGetIdent();
}
