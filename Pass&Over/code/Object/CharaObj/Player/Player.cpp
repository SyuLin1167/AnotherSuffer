#include"../../../Asset/Model/Model.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    //ÉÇÉfÉãì«Ç›çûÇ›
    Model* model = AssetManager::ModelInstance();
    auto& modelPass = model->GetJsonData();
    auto objHandle = model->GetHandle(modelPass["player"].GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, VGet(0.5f, 0.5f, 0.5f));
    
}

Player::~Player()
{
    //èàóùÇ»Çµ
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    if (CheckHitKey(KEY_INPUT_P))
    {
        isAlive = false;
    }

}

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}