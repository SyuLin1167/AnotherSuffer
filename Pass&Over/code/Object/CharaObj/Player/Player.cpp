#include"../../../Asset/Model/Model.h"
#include "Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    //モデル読み込み
    Model* model = AssetManager::ModelInstance();
    auto& modelPass = model->GetJsonData();
    auto objHandle = model->GetHandle(modelPass["player"].GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, VGet(0.5f, 0.5f, 0.5f));
    
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="deltaTime"></param>
void Player::Update(const float deltaTime)
{
    a += deltaTime;
    if (CheckHitKey(KEY_INPUT_P))
    {
        isAlive = false;
    }

}

/// <summary>
/// 描画処理
/// </summary>
void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}