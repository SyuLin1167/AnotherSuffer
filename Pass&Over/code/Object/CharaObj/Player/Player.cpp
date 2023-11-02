#include"../../../KeyStatus/KeyStatus.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
{
    //���f���ǂݍ���
    auto& modelPass = AssetManager::ModelInstance()->GetJsonData()[objTag.c_str()];
    objHandle = AssetManager::ModelInstance()->GetHandle(modelPass.GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, objScale);

    //�T�E���h�ǂݍ���
    auto& soundPass = AssetManager::SoundInstance()->GetJsonData()[objTag.c_str()];
}

Player::~Player()
{
    //�����Ȃ�
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    AssetManager::MotoinInstance()->AddMotionTime(deltaTime);
    if (KeyStatus::KeyStateDecision(KEY_INPUT_A, deltaTime, NOWINPUT))
    {
        objPos.z -= 10.0f * deltaTime;
        auto& motionPass = AssetManager::MotoinInstance()->GetJsonData()[objTag.c_str()];
        AssetManager::MotoinInstance()->StartMotion(objHandle, AssetManager::MotoinInstance()->GetHandle(
            motionPass[jsondata::objKey.walk.c_str()][jsondata::dataKey.pass.c_str()].GetString()));
    }
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, deltaTime, ONINPUT))
    {
        isAlive = false;
        auto& soundPass = AssetManager::SoundInstance()->GetJsonData()[objTag.c_str()];
        AssetManager::SoundInstance()->StartSound(AssetManager::SoundInstance()->GetHandle(
            soundPass[jsondata::objKey.walk.c_str()][jsondata::dataKey.pass.c_str()].GetString()));
    }
    MV1SetPosition(objHandle, objPos);
}

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}