#include<DxLib.h>

#include "Player.h"

// �R���X�g���N�^ //

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{

}

// �f�X�g���N�^ //

Player::~Player()
{

}

// �X�V���� //

void Player::Update(const float& deltaTime)
{
    a += 1*deltaTime;
    if (CheckHitKey(KEY_INPUT_P))
    {
        isAlive = false;
    }
}

// �`�揈�� //

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%d", a);
}