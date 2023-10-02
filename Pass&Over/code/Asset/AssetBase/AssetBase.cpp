#include "AssetBase.h"

// �R���X�g���N�^ //

AssetBase::AssetBase()
{

}

// �f�X�g���N�^ //

AssetBase::~AssetBase()
{

}

// Json�t�@�C���ǂݍ��ݏ��� //

void AssetBase::LoadJsonFile(std::string fileName)
{
    //�t�@�C���ǂݍ���
    std::ifstream ifs(fileName.c_str());

    //�t�@�C�����
    if (ifs.good())
    {
        rapidjson::IStreamWrapper isw(ifs);

        doc.ParseStream(isw);
    }
    ifs.close();
}

// �n���h���擾���� //

int AssetBase::GetHandle(std::string handleName)
{
    //�擾�������n���h��������������Ԃ�
    auto iter = handle.find(handleName);
    if (iter != handle.end())
    {
        return handle[handleName];
    }

    //������Ȃ�������-1��Ԃ�
    return -1;
}