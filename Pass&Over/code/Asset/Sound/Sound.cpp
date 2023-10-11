#include<DxLib.h>

#include "Sound.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Sound::Sound()
{
    assetType = "sound";

    //json�t�@�C���ǂݍ���
    jsonFile = "../code/Asset/Model/ModelData.json";
    LoadJsonFile(jsonFile);

    //�n���h���ǉ�
    auto& data = GetJsonData();
    AddHandle(data["player"]["walk"].GetString());
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Sound::~Sound()
{
    //�����Ȃ�
}

/// <summary>
/// �n���h���ǉ�����
/// </summary>
/// <param name="fileName">:�t�@�C����</param>
void Sound::AddHandle(const std::string fileName)
{
    //���n���h��������
    holdHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto iter = handle.find(fileName);
    if (iter == handle.end())
    {
        holdHandle = LoadSoundMem(fileName.c_str());
        dupHandle = DuplicateSoundMem(holdHandle);
        handle.emplace(fileName, dupHandle);
    }
}