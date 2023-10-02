#include<DxLib.h>

#include"../../../Asset/Model/Model.h"
#include "Player.h"

// �R���X�g���N�^ //

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    AssetMgr::ModelInstance()->GetHandle();
}

// �f�X�g���N�^ //

Player::~Player()
{

}

// �X�V���� //

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    if (CheckHitKey(KEY_INPUT_P))
    {
        isAlive = false;
    }
}

// �`�揈�� //

void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
}