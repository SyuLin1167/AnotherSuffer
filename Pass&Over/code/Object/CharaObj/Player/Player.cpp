#include"../../../Asset/Model/Model.h"
#include "Player.h"

// �R���X�g���N�^ //

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    //���f���ǂݍ���
    Model* model = AssetMgr::ModelInstance();
    objHandle = model->GetHandle("../assets/Chara/Player/Player.mv1");
    MV1SetPosition(objHandle, VGet(0, 0, 0));
    MV1SetScale(objHandle, VGet(0.5f, 0.5f, 0.5f));
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
    MV1DrawModel(objHandle);
}