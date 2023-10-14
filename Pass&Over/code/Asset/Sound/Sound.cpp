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
    //�����Ȃ�
}

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

void Sound::AddData(const rapidjson::Value& key)
{
    SoundParam param = {};
    param.isLoop = key["loop"].GetBool();
    param.volume = key["volume"].GetInt();

    soundData.emplace(GetHandle(key["pass"].GetString()), param);
}

Sound::SoundParam::SoundParam()
    :isLoop(false)
    , volume(0)
{
    //�����Ȃ�
}
