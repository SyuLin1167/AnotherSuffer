#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// �ǃu���b�N
/// </summary>
class Wall final:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Wall(VECTOR pos);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Wall();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// ����O�؂蔲������
    /// </summary>
    void ViewClipBox();

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    std::shared_ptr<ObjBase> player;        //�v���C���[

    VECTOR clipBoxScale;                    //�؂蔲���{�b�N�X�X�P�[��
    VECTOR clipBoxPos1;                     //�؂蔲���{�b�N�X���W1
    VECTOR clipBoxPos2;                     //�؂蔲���{�b�N�X���W2

    int texHandle;
    int texIndex;
};

