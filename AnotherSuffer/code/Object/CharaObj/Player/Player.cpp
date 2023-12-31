#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
    ,colInfo()
    ,moveVel()
{
    //モデル読み込み
    objHandle = model->GetHandle(modelData.GetString());
    frameIdx = 0;
    objDir = VGet(0, 0, -1);
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

    motion->StartMotion(objHandle,
        motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));

    //移動速度は走る速度
    moveSpeed = RUN_SPEED*2;

    capsule=new Capsule(VAdd(objPos, VGet(0, 6, 0)), VAdd(objPos, VGet(0, 30, 0)), 6.0f);

    texHandle = CreatePointLightHandle(objPos, 150.0f, 0.0f, 0.0f, 0.001f);
}

Player::~Player()
{
    //処理なし
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    //アニメーション時間再生
    motion->AddMotionTime(deltaTime);

    //キャラ移動
    MoveChara(deltaTime);

    //停止中
    if(!isMove)
    {
        //通常時アニメーション再生
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
    }

    //Pキーが押されたら
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, ONINPUT))
    {
        //死亡にする
        isAlive = false;

        //サウンド再生
        sound->StartSound(sound->GetHandle(GetFilePass(soundData[jsondata::objKey.walk.c_str()])));
    }

    if (KeyStatus::KeyStateDecision(KEY_INPUT_SPACE, ONINPUT))
    {
        frameIdx++;
    }

    //座標更新
    CalcObjPos();

    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Player::MoveChara(const float deltaTime)
{
    //停止中にする
    isMove = false;

    //カメラの向きを自身の移動方向とする
    std::shared_ptr<ObjBase> camera = ObjManager::GetObj(ObjTag.CAMERA)[0];
    SetLightPositionHandle(texHandle, camera->GetObjPos());
    VECTOR aimDir = camera->GetObjDir();
    VECTOR rightDir = VCross(VGet(0, -1, 0), aimDir);
    aimDir.y = 0;
    aimDir = VNorm(aimDir);

    //キー入力による移動量
    moveVel = VGet(0, 0, 0);
    MoveByKey(KEY_INPUT_W, aimDir, deltaTime);
    MoveByKey(KEY_INPUT_S, VScale(aimDir, -1), deltaTime);
    MoveByKey(KEY_INPUT_A, rightDir, deltaTime);
    MoveByKey(KEY_INPUT_D, VScale(rightDir, -1), deltaTime);
    moveVel.y = 0;

    //座標・方向の算出
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));
    rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //キーが入力されていたら移動時の実行
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel = VNorm(VAdd(moveVel, dir));

        //移動アニメーション再生
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //動作中にする
        isMove = true;
    }
}

void Player::OnCollisionEnter(ObjBase* colObj)
{
    if (capsule->OnCollisionWithMesh(colObj->GetObjHandle(), colInfo))
    {
        a = 0;
        objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh(colInfo));

        MV1CollResultPolyDimTerminate(colInfo);
    }

    //座標更新
    CalcObjPos();
    capsule->Update(objPos);

    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
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

    DrawFormatString(0, 20, GetColor(255, 255, 255), "%f", a);
    DrawLine3D(objPos, VAdd(objPos, VScale(objDir,3)), GetColor(255, 0, 0));

#endif // _DEBUG
}