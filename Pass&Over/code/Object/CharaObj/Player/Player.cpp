#include"../../../Asset/Model/Model.h"
#include "Player.h"

// コンストラクタ //

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    //モデル読み込み
    Model* model = AssetMgr::ModelInstance();
    auto& modelPass = model->GetJsonData();
    objHandle = model->GetHandle(modelPass["player"].GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, VGet(0.5f, 0.5f, 0.5f));
    
}

// デストラクタ //

Player::~Player()
{
    //処理なし
}

// 更新処理 //

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    if (CheckHitKey(KEY_INPUT_P))
    {
        isAlive = false;
    }

}

// 描画処理 //

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}