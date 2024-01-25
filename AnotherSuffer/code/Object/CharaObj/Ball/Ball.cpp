#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include"../../Math/Math.h"
#include "Ball.h"

static constexpr float SPEED = 1.0f;
static constexpr float MAX_SPEED = 40.0f;
static constexpr float MIN_SPEED = 0.0f;

Ball::Ball()
    :CharaObjBase(ObjTag.BALL)
    , moveVel(VGet(0, 0, 0))
    , canMove(true)
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
    RotateVel();

    //行列でモデルの動作
    objPos.y = capsule->GetRadius();
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale),MMult(rotateXMat,rotateZMat)), MGetTranslate(VAdd(objPos,objDir))));
}

void Ball::MoveChara(const float deltaTime)
{
    //停止中にする
    isMove = false;

    //キー入力による移動量
    if (canMove)
    {
        MoveByKey(KEY_INPUT_W, VGet(1.0f, 0, 0), deltaTime);
        MoveByKey(KEY_INPUT_S, VGet(-1.0f, 0, 0), deltaTime);
        MoveByKey(KEY_INPUT_A, VGet(0, 0, 1.0f), deltaTime);
        MoveByKey(KEY_INPUT_D, VGet(0, 0, -1.0f), deltaTime);
    }
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
        if (moveSpeed < 0.2f)
        {
            moveVel = VGet(0, 0, 0);
            moveSpeed = MIN_SPEED;
            canMove = true;
        }
    }
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));

}

void Ball::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{

    //キーが入力されていたら移動時の実行
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel = VAdd(moveVel, dir);

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
                canMove = false;
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
#endif // _DEBUG
}

void Ball::RotateVel()
{
    rotateXMat = MGetIdent();
    rotateZMat = MGetIdent();

    if (static_cast<int>(abs(moveVel.z)) > 0)
    {
        if (objDir.x > 0)
        {
            RotateXAxis(VScale(moveVel, -1), VSize(moveVel) * moveSpeed / 8.0f);
        }
        else
        {
            RotateXAxis(moveVel, VSize(moveVel) * moveSpeed / 8.0f);
        }
    }

    if (static_cast<int>(abs(moveVel.x)) > 0)
    {
        if (objDir.z > 0)
        {
            RotateZAxis(VScale(moveVel, -1), VSize(moveVel) * moveSpeed / 8.0f);
        }
        else
        {
            RotateZAxis(moveVel, VSize(moveVel) * moveSpeed / 8.0f);
        }
    }
}
