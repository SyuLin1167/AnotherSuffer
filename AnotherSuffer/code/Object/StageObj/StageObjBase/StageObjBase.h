#pragma once
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// �X�e�[�W�I�u�W�F�N�g�̊��N���X
/// </summary>
class StageObjBase:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="pos">:���W</param>
    StageObjBase(const VECTOR pos);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~StageObjBase();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    /// <summary>
    /// ����O�؂蔲��
    /// </summary>
    void ViewClipBox();

    ObjBase* player;        //�v���C���[

protected:
    /// <summary>
    /// �����蔻�菉����
    /// </summary>
    void InitCollision();

    const rapidjson::Value& graphData;      //�O���t�p�X�f�[�^

    VECTOR clipBoxScale;        //�؂蔲���{�b�N�X�X�P�[��
    VECTOR clipBoxPos1;         //�؂蔲���{�b�N�X���W1
    VECTOR clipBoxPos2;         //�؂蔲���{�b�N�X���W2

    int texHandle;              //�e�N�X�`���n���h��
    int texIndex;               //�e�N�X�`���C���f�b�N�X

    unsigned int color;

    std::unique_ptr<class ColModel> colModel;   //�����蔻��
};

