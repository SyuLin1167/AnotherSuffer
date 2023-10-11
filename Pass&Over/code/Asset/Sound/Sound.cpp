#include<DxLib.h>

#include "Sound.h"

/// <summary>
/// コンストラクタ
/// </summary>
Sound::Sound()
{
    assetType = "sound";

    //jsonファイル読み込み
    jsonFile = "../code/Asset/Model/ModelData.json";
    LoadJsonFile(jsonFile);

    //ハンドル追加
    auto& data = GetJsonData();
    AddHandle(data["player"]["walk"].GetString());
}

/// <summary>
/// デストラクタ
/// </summary>
Sound::~Sound()
{
    //処理なし
}

/// <summary>
/// ハンドル追加処理
/// </summary>
/// <param name="fileName">:ファイル名</param>
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