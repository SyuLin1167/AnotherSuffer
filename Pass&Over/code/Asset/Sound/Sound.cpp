#include<DxLib.h>

#include "Sound.h"

Sound::Sound()
{
    assetType = "sound";

    //jsonファイル読み込み
    jsonFile = "../code/Asset/Sound/SoundData.json";
    LoadJsonFile(jsonFile);

    //ハンドル追加
    for (rapidjson::Value::ConstMemberIterator iter = GetJsonData()["player"].MemberBegin(); iter != GetJsonData()["player"].MemberEnd(); iter++)
    {

    }
    AddHandle(playerData["walk"]["pass"].GetString());
    AddData(playerData["walk"]);
}

Sound::~Sound()
{
    //処理なし
}

void Sound::AddHandle(const std::string fileName)
{
    //仮ハンドル初期化
    holdHandle = -1;
    dupHandle = -1;

    //ファイルが見つからなかったらハンドルを複製して追加
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
    //処理なし
}
