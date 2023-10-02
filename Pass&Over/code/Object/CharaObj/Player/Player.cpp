#include<DxLib.h>

#include"../../../Asset/Model/Model.h"
#include "Player.h"

// コンストラクタ //

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    AssetMgr::ModelInstance()->GetHandle();
}

// デストラクタ //

Player::~Player()
{

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
}