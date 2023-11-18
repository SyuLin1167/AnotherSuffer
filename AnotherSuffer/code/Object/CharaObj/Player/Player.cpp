#include"../../../KeyStatus/KeyStatus.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
{
    //モデル読み込み
    objHandle = model->GetHandle(modelData.GetString());
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

    motion->StartMotion(objHandle,
        motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));

    //移動速度は走る速度
    moveSpeed = RUN_SPEED;
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

    //動作中
    if (isMove)
    {
        //オブジェクトの座標算出
        CalcObjPos();

        //行列でモデルの動作
        MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
    }
    //停止中
    else
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

    //停止中にする
    isMove = false;
}

void Player::MoveChara(const float deltaTime)
{
    //キー入力による上下左右移動
    MoveByKey(KEY_INPUT_W, FRONT, deltaTime);
    MoveByKey(KEY_INPUT_S, BACK, deltaTime);
    MoveByKey(KEY_INPUT_A, LEFT, deltaTime);
    MoveByKey(KEY_INPUT_D, RIGHT, deltaTime);
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //キーが入力されていたら移動時の処理実行
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        //移動アニメーション再生
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //座標・方向の算出
        objLocalPos = VAdd(objLocalPos, VScale(dir, moveSpeed * deltaTime));
        RotateYAxis(dir, ROTATE_SPEED);

        //動作中にする
        isMove = true;
    }
}

void Player::Draw()
{
    //モデル描画
    MV1DrawModel(objHandle);

    DrawLine3D(objPos, VAdd(objPos, VScale(objDir,3)), GetColor(255, 0, 0));
}