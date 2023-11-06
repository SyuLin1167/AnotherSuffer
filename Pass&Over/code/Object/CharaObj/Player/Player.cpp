#include"../../../KeyStatus/KeyStatus.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
{
    //ƒ‚ƒfƒ‹“Ç‚Ýž‚Ý
    objHandle = model->GetHandle(modelData.GetString());
    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, objScale);

    motion->StartMotion(objHandle,
        motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
}

Player::~Player()
{
    //ˆ—‚È‚µ
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    motion->AddMotionTime(deltaTime);
    if (KeyStatus::KeyStateDecision(KEY_INPUT_A, NOWONINPUT))
    {
        objPos.z -= 10.0f * deltaTime;
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.walk.c_str()])));
    }
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, ONINPUT))
    {
        isAlive = false;
        sound->StartSound(sound->GetHandle(GetFilePass(soundData[jsondata::objKey.walk.c_str()])));
    }

    VECTOR v = MV1GetFrameAvgVertexLocalPosition(objHandle, 2);
    MATRIX m1 = MGetTranslate(VGet(v.x, v.y, v.z));
    MATRIX m2 = MGetTranslate(VGet(-v.x, -v.y, -v.z));
    MV1SetFrameUserLocalMatrix(objHandle, 2, MMult(MMult(m2, MGetRotY(((2 * DX_PI_F) / 60) * a*5)), m1));

    MV1SetPosition(objHandle, objPos);
}

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}