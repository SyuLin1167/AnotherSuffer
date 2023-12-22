#pragma once

/// <summary>
/// �X�e�[�W�I�u�W�F�N�g�̊��N���X
/// </summary>
class StageObjBase:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    StageObjBase();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~StageObjBase();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// ����O�؂蔲��
    /// </summary>
    void ViewClipBox();

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

protected:
    VECTOR clipBoxScale;                    //�؂蔲���{�b�N�X�X�P�[��
    VECTOR clipBoxPos1;                     //�؂蔲���{�b�N�X���W1
    VECTOR clipBoxPos2;                     //�؂蔲���{�b�N�X���W2
};

