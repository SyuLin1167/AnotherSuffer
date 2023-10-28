#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// モデルのモーション管理
/// </summary>
class Motion final:public AssetBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Motion();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Motion();

    /// <summary>
    /// モーション再生処理
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    void StartMotion(int handle);

    /// <summary>
    /// モーション停止処理
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    void StopMotion(int handle);

private:
    /// <summary>
    /// ハンドル追加処理
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(std::string fileName) override;

    /// <summary>
    /// データ追加処理
    /// </summary>
    /// <param name="key">:jsonデータ取得キー</param>
    void AddData(const rapidjson::Value& key);

    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() override;

    /// <summary>
    /// モーションパラメーター
    /// </summary>
    struct MotionParam
    {
    public:
        MotionParam();

        int index;                  //インデックス番号
        float totalTime;            //総再生時間
        float playSpeed;            //再生速度
        bool isLoop;                //ループ再生判定
    };

    int modelHandle;                                      //モデルハンドル
    std::unordered_map<int, MotionParam> motionData;      //モーションデータ
};

