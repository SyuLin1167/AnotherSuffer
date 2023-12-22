#include<DxLib.h>

#include "Sound.h"

Sound::Sound()
{
    //jsonファイル読み込み
    jsonFile = "../json/SoundData.json";
    LoadJsonFile(jsonFile);

    //オブジェクト分データ追加
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        for (rapidjson::Value::ConstMemberIterator soundType = objType->value.MemberBegin();
            soundType != objType->value.MemberEnd(); soundType++)
        {
            AddHandle(soundType->value[jsondata::dataKey.pass.c_str()].GetString());
            AddData(soundType->value);
        }
    }
}

Sound::~Sound()
{
    MV1DeleteModel(holdHandle);
    MV1DeleteModel(dupHandle);
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
    //ハンドル検索
    auto handle = GetHandle(key[jsondata::dataKey.pass.c_str()].GetString());
    auto findData = soundData.find(handle);

    //見つからなかったらサウンドデータ追加
    if (findData == soundData.end())
    {
        SoundParam param = {};
        param.soundType = key[jsondata::dataKey.type.c_str()].GetString();
        param.isLoop = key[jsondata::dataKey.loop.c_str()].GetBool();
        param.volume = key[jsondata::dataKey.volume.c_str()].GetInt();

        soundData.emplace(handle, param);
    }
}

Sound::SoundParam::SoundParam()
    :soundType("")
    , isLoop(false)
    , volume()
{
    //処理なし
}

void Sound::DeleteHandle()
{
    //ハンドルとデータ解放
    for (auto& iter : handle)
    {
        DeleteSoundMem(iter.second);
    }
    handle.clear();
    soundData.clear();
}

void Sound::StartSound(const int& handle)
{
    //再生状態を確認して再生
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

void Sound::StopSound(const int& handle)
{
    //再生状態を確認して停止
    if (CheckSoundMem(handle))
    {
        StopSoundMem(handle);
    }
}