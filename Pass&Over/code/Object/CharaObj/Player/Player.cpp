#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
{
    //���f���ǂݍ���
    model = AssetManager::ModelInstance();
    auto& modelPass = model->GetJsonData()[objTag.c_str()];
    objHandle = model->GetHandle(modelPass.GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, objScale);

    //�T�E���h�ǂݍ���
    sound = AssetManager::SoundInstance();
    auto& soundPass = sound->GetJsonData()[objTag.c_str()];
}

Player::~Player()
{
    //�����Ȃ�
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    if (CheckHitKey(KEY_INPUT_P))
    {
        isAlive = false;
        auto& soundPass = sound->GetJsonData()[objTag.c_str()];
        sound->StartSound(sound->GetHandle(
            soundPass[jsonObjKey.walk.c_str()][jsonDataKey.pass.c_str()].GetString()
        ));
    }

}

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}