#include"ObjTag.h"
#include "ObjBase.h"

// �R���X�g���N�^ //

ObjBase::ObjBase(ObjTag tag)
    :objTag(tag)
{

}

// �f�X�g���N�^ //

ObjBase::~ObjBase()
{

}

// �I�u�W�F�N�g�^�O�擾 //

ObjTag& ObjBase::GetTag()
{
    return objTag;
}