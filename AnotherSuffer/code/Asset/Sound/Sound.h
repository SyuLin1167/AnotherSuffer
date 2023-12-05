#pragma once

#include"../AssetBase/AssetBase.h"

/// <summary>
/// サウンド管理
/// </summary>
class Sound final:public AssetBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Sound();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Sound();

    /// <summary>
    /// サウンド再生処理
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    void StartSound(const int& handle);

    /// <summary>
    /// サウンド停止処理
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    void StopSound(const int& handle);

    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() override;

private:
    /// <summary>
    /// ハンドル追加処理
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(std::string fileName) override ;

    /// <summary>
    /// データ追加処理
    /// </summary>
    /// <param name="key">:jsonデータ取得キー</param>
    void AddData(const rapidjson::Value& key);

    /// <summary>
    /// サウンドパラメーター
    /// </summary>
    struct SoundParam
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        SoundParam();

        std::string soundType;                          //サウンドタイプ
        bool isLoop;                                    //ループ再生判定
        int volume;                                     //音量
    };

    std::unordered_map<int, SoundParam> soundData;      //サウンドデータ
};

