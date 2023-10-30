#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
{
    //���f���ǂݍ���
    model.reset(AssetManager::ModelInstance());
    auto& modelPass = model->GetJsonData()[objTag.c_str()];
    objHandle = model->GetHandle(modelPass.GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, objScale);

    //���[�V�����ǂݍ���
    motion.reset(AssetManager::MotoinInstance());

    //�T�E���h�ǂݍ���
    sound.reset(AssetManager::SoundInstance());
    auto& soundPass = sound->GetJsonData()[objTag.c_str()];
}

Player::~Player()
{
    //�����Ȃ�
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    motion->AddMotionTime(deltaTime);
    if (CheckHitKey(KEY_INPUT_A))
    {
        auto& motionPass = motion->GetJsonData()[objTag.c_str()];
        motion->StartMotion(objHandle, motion->GetHandle(
            motionPass[jsondata::objKey.walk.c_str()][jsondata::dataKey.pass.c_str()].GetString()));
    }
    if (CheckHitKey(KEY_INPUT_P))
    {
        isAlive = false;
        auto& soundPass = sound->GetJsonData()[objTag.c_str()];
        sound->StartSound(sound->GetHandle(
            soundPass[jsondata::objKey.walk.c_str()][jsondata::dataKey.pass.c_str()].GetString()));
    }
}

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}