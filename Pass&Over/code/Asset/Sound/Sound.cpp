#include<DxLib.h>

#include "Sound.h"

Sound::Sound()
{
    assetType = "sound";

    //jsonファイル読み込み
    jsonFile = "../code/Asset/Sound/SoundData.json";
    LoadJsonFile(jsonFile);

    //ハンドル追加
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
    //仮ハンドル初期化
    holdHandle = -1;
    dupHandle = -1;

    //ファイルが見つからなかったらハンドルを複製して追加
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
    //ハンドルが見つからなかったらサウンドデータ追加
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
    //処理なし
}

void Sound::DeleteHandle()
{
    //ハンドルとハンドルを確保したデータ解放
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