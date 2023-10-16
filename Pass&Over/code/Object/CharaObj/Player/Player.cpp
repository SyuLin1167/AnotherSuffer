#include"../../../Asset/Model/Model.h"
#include"../../../Asset/Sound/Sound.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    //モデル読み込み
    Model* model = AssetManager::ModelInstance();
    auto& modelPass = model->GetJsonData();
    objHandle = model->GetHandle(modelPass["player"].GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, objScale);
    
    //サウンド読み込み
    sound = AssetManager::SoundInstance();
    auto& soundPass = sound->GetJsonData();
}

Player::~Player()
{
    //処理なし
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