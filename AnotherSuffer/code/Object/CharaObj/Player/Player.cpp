#include"../../../KeyStatus/KeyStatus.h"
#include"../../Math/Math.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include"../../../Collision/Line/Line.h"
#include "Player.h"

static constexpr float RUN_SPEED = 40.0f;
static constexpr float CAPSULE_RAD = 7.0f;

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
    ,moveVel()
{
    //モデル読み込み
    objHandle = AssetManager::ModelInstance()->GetHandle(modelData.GetString());
    objDir = VGet(0, 0, -1);
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale),YAxisData->GetRotateMat()), MGetTranslate(objPos)));

    AssetManager::MotionInstance()->StartMotion(this,
        AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));

    //移動速度は走る速度
    moveSpeed = RUN_SPEED;

    //当たり判定はカプセル型
    capsule = new Capsule(VAdd(objWorldPos, VGet(0, 6, 0)), VAdd(objWorldPos, VGet(0, 30, 0)), CAPSULE_RAD);
    capsule->Update(objPos);
    CollisionManager::AddCol(this, capsule);
    line = new Line(VAdd(objPos, VGet(0, 5, 0)), VAdd(objPos, VGet(0, -5, 0)));
    CollisionManager::AddCol(this, line);

    //仮ライト
    texHandle = CreateSpotLightHandle(objPos,objDir,DX_PI_F,DX_PI_F/2, 150.0f, 0.0f, 0.0f, 0.0005f);
    test = 0;
}

Player::~Player()
{
    //処理なし
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    //アニメーション時間再生
    AssetManager::MotionInstance()->AddMotionTime(this, deltaTime);

    //キャラ移動
    MoveChara(deltaTime);

    //停止中
    if(!isMove)
    {
        //通常時アニメーション再生
        AssetManager::MotionInstance()->StartMotion(this,
            AssetManager::MotionInstance()->GetHandle(
                AssetManager::GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
    }

    //Pキーが押されたら
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, ONINPUT))
    {
        //死亡にする
        isAlive = false;

        //サウンド再生
        AssetManager::SoundInstance()->StartSound(
        AssetManager::SoundInstance()->GetHandle(
        AssetManager::GetFilePass(soundData[jsondata::objKey.walk.c_str()])));
    }

    //座標更新
    CalcObjPos();
    
    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));
}

void Player::MoveChara(const float deltaTime)
{
    //停止中にする
    isMove = false;

    //カメラの向きを自身の移動方向とする
    ObjBase* camera = ObjManager::GetObj(ObjTag.CAMERA,0);
    SetLightDirectionHandle(texHandle, camera->GetObjDir());
    SetLightPositionHandle(texHandle, camera->GetObjPos());
    VECTOR aimDir = camera->GetObjDir();
    VECTOR rightDir = VCross(VGet(0, -1, 0), aimDir);
    aimDir = VNorm(aimDir);
    aimDir.y = 0;

    //キー入力による移動量
    moveVel = VGet(0, 0, 0);
    MoveByKey(KEY_INPUT_W, aimDir, deltaTime);
    MoveByKey(KEY_INPUT_S, VScale(aimDir, -1), deltaTime);
    MoveByKey(KEY_INPUT_A, rightDir, deltaTime);
    MoveByKey(KEY_INPUT_D, VScale(rightDir, -1), deltaTime);

    //座標・方向の算出
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));
    YAxisData->RotateToAim(aimDir);
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //キーが入力されていたら移動時の実行
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel = VNorm(VAdd(moveVel, dir));

        //移動アニメーション再生
        AssetManager::MotionInstance()->StartMotion(this,
            AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //動作中にする
        isMove = true;
    }
}

void Player::OnCollisionEnter(ObjBase* colObj)
{
    //当たり判定処理
    for (auto& obj : CollisionManager::GetCol(colObj))
    {
        if (obj->GetColTag() == ColTag.MODEL)
        {
            if (capsule->OnCollisionWithMesh(obj->GetColModel()))
            {
                objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh());

                MV1CollResultPolyDimTerminate(capsule->GetColInfoDim());
            }
            if (line->OnCollisionWithMesh(obj->GetColModel()))
            {
                test = -1;
            }
        }
    }

    //座標更新
    CalcObjPos();
    capsule->Update(objPos);
    line->Update(objPos);

    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));
}

void Player::Draw()
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

    DrawFormatString(0, 100, GetColor(255, 255, 255), "%d",test);

    DrawFormatString(1050, 0, GetColor(255, 255, 255), "自身座標%f,%f", capsule->GetWorldStartPos().x, capsule->GetWorldStartPos().z);
#endif // _DEBUG
}