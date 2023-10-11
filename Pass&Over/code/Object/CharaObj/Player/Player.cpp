#include"../../../Asset/Model/Model.h"
#include "Player.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player()
    :CharaObjBase(ObjTag::PLAYER)
{
    //���f���ǂݍ���
    Model* model = AssetManager::ModelInstance();
    auto& modelPass = model->GetJsonData();
    auto objHandle = model->GetHandle(modelPass["player"].GetString());

    MV1SetPosition(objHandle, objPos);
    MV1SetScale(objHandle, VGet(0.5f, 0.5f, 0.5f));
    
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Player::~Player()
{
    //�����Ȃ�
}

/// <summary>
/// �X�V����
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
/// �`�揈��
/// </summary>
void Player::Draw()
{
    DrawFormatString(0, 50, GetColor(255, 255, 255), "player:%f", a);
    MV1DrawModel(objHandle);
}