#include "ObjBase.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="tag"></param>
ObjBase::ObjBase(ObjTag tag)
    :objTag(tag)
    , isAlive(true)
    , isVisible(true)
    , objHandle(-1)
    , objPos(VGet(0, 0, 0))
    , objDir(VGet(1, 0, 0))
{
    //�����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
ObjBase::~ObjBase()
{
    //�����Ȃ�
}

/// <summary>
/// �I�u�W�F�N�g�^�O�擾
/// </summary>
/// <returns>�I�u�W�F�N�g�^�O</returns>
ObjTag& ObjBase::GetTag()
{
    return objTag;
}