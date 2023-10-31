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
    /// <param name="model">:モデルインスタンス</param>
    Motion(class Model* model);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Motion();

    /// <summary>
    /// モーション時間経過処理
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void AddMotionTime( const float deltaTime);

    /// <summary>
    /// モーション再生処理
    /// </summary>
    /// <param name="model">:モデルハンドル</param>
    /// <param name="handle">:ハンドル</param>
    void StartMotion(int model, int handle);

    /// <summary>
    /// モーション停止処理
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    void StopMotion();

    /// <summary>
    /// 再生判定
    /// </summary>
    /// <returns>再生中:true|停止中:false</returns>
    bool IsPlaying();
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

        float playSpeed;            //再生速度
        bool isLoop;                //ループ再生判定
        int index;                  //インデックス番号
        float totalTime;            //総再生時間
    };

    int modelHandle;                                    //モデルハンドル
    float nowMotionTime;                                //現在のモーション時間

    int nowHandle;                                      //現在のハンドル

    std::unordered_map<int, MotionParam> motionData;    //モーションデータ
    std::unordered_map<int, int> attachedIndex;         //アタッチ後のインデックスデータ
};

