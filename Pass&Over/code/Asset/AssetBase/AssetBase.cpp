#include "AssetBase.h"

// �R���X�g���N�^ //

AssetBase::AssetBase()
{

}

// �f�X�g���N�^ //

AssetBase::~AssetBase()
{

}

// �n���h���擾���� //

int AssetBase::GetHandle(std::string handleName)
{
    //�擾�������n���h��������������Ԃ�
    auto iter = handle.find(handleName);
    if (iter != handle.end())
    {
        return *handle[handleName];
    }

    //������Ȃ�������-1��Ԃ�
    return -1;
}