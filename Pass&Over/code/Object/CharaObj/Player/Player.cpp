#include"../../../Asset/Model/Model.h"
#include "Player.h"

// �R���X�g���N�^ //

Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    //���f���ǂݍ���
    Model* model = AssetMgr::ModelInstance();
    auto& modelPass = model->GetJsonData();
    objHandle = model->GetHandle(modelPass["player"].GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, VGet(0.5f, 0.5f, 0.5f));
    
}

// �f�X�g���N�^ //

Player::~Player()
{
    //�����Ȃ�
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