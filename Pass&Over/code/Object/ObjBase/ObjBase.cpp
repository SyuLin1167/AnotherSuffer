#include "ObjBase.h"

// �R���X�g���N�^ //

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

// �f�X�g���N�^ //

ObjBase::~ObjBase()
{
    //�����Ȃ�
}

// �I�u�W�F�N�g�^�O�擾 //

ObjTag& ObjBase::GetTag()
{
    return objTag;
}