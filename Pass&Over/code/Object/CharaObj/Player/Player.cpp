#include"../../../Asset/Model/Model.h"
#include"../../../Asset/Sound/Sound.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    //���f���ǂݍ���
    Model* model = AssetManager::ModelInstance();
    auto& modelPass = model->GetJsonData();
    objHandle = model->GetHandle(modelPass["player"].GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, objScale);
    
    //�T�E���h�ǂݍ���
    sound = AssetManager::SoundInstance();
    auto& soundPass = sound->GetJsonData();
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
        auto& soundPass = sound->GetJsonData();
        sound->StartSound(sound->GetHandle(soundPass["player"]["walk"]["pass"].GetString()));
    }

}

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}