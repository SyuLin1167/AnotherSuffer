#include<DxLib.h>

#include "Player.h"

// コンストラクタ //

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{

}

// デストラクタ //

Player::~Player()
{

}

// 更新処理 //

void Player::Update(const float& deltaTime)
{
    a += 1*deltaTime;
    if (CheckHitKey(KEY_INPUT_P))
    {
        isAlive = false;
    }
}

// 描画処理 //

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%d", a);
}