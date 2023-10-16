#include<DxLib.h>

#include "Sound.h"

Sound::Sound()
{
    assetType = "sound";

    //json�t�@�C���ǂݍ���
    jsonFile = "../code/Asset/Sound/SoundData.json";
    LoadJsonFile(jsonFile);

    //�n���h���ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        for (rapidjson::Value::ConstMemberIterator soundType = objType->value.MemberBegin();
            soundType != objType->value.MemberEnd(); soundType++)
        {
            AddHandle(soundType->value["pass"].GetString());
            AddData(soundType->value);
        }
    }
}

Sound::~Sound()
{
    DeleteHandle();
}

void Sound::AddHandle(const std::string fileName)
{
    //���n���h��������
    holdHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto findHandle = handle.find(fileName);
    if (findHandle == handle.end())
    {
        holdHandle = LoadSoundMem(fileName.c_str());
        dupHandle = DuplicateSoundMem(holdHandle);
        handle.emplace(fileName, dupHandle); 
    }
}

void Sound::AddData(const rapidjson::Value& key)
{
    //�n���h����������Ȃ�������T�E���h�f�[�^�ǉ�
    auto handle = GetHandle(key["pass"].GetString());
    auto findData = soundData.find(handle);

    if (findData == soundData.end())
    {
        SoundParam param = {};
        param.soundType = key["type"].GetString();
        param.isLoop = key["loop"].GetBool();
        param.volume = key["volume"].GetInt();

        soundData.emplace(handle, param);
    }
}

Sound::SoundParam::SoundParam()
    :soundType("")
    , isLoop(false)
    , volume(0)
{
    //�����Ȃ�
}

void Sound::DeleteHandle()
{
    //�n���h���ƃn���h�����m�ۂ����f�[�^���
    for (auto& iter : handle)
    {
        DeleteSoundMem(iter.second);
    }
    handle.clear();
    soundData.clear();
}

void Sound::StartSound(int handle)
{
    if (!CheckSoundMem(handle))
    {
        if (soundData[handle].isLoop)
        {
            PlaySoundMem(handle, DX_PLAYTYPE_LOOP);
        }
        else
        {
            PlaySoundMem(handle, DX_PLAYTYPE_BACK);
        }
    }
}

void Sound::StopSound(int handle)
{
    if (CheckSoundMem(handle))
    {
        StopSoundMem(handle);
    }
}