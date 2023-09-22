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
    auto iter = std::find(handle.begin(), handle.end(), handleName);
    if (iter != handle.end())
    {
        return handle[handleName];
    }

    //������Ȃ�������-1��Ԃ�
    return -1;
}

// �n���h���폜���� //

void AssetBase::DeleteHandle()
{
        handle.clear();
}