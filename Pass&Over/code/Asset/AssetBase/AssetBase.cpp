#include<DxLib.h>

#include "AssetBase.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
AssetBase::AssetBase()
    :holdHandle(-1)
    , dupHandle(-1)
    , assetType("")
    , jsonFile("")
{
    //�����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
AssetBase::~AssetBase()
{
    //�����Ȃ�
}

/// <summary>
/// Json�t�@�C���ǂݍ��ݏ���
/// </summary>
/// <param name="fileName"></param>
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

/// <summary>
/// �n���h���擾����
/// </summary>
/// <param name="handleName">:�n���h����</param>
/// <returns>�n���h��</returns>
const int AssetBase::GetHandle(std::string handleName)
{
    //�擾�������n���h��������������Ԃ�
    auto iter = handle.find(handleName);
    if (iter != handle.end())
    {
        if (!CheckHandleASyncLoad(handle[handleName]))
        {
            return handle[handleName];
        }
    }

    //�Ԃ��Ȃ�������-1��Ԃ�
    return -1;
}