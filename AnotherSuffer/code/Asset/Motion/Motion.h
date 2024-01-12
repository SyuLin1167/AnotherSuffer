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
    /// モーション時間経過
    /// </summary>
    /// <param name="obj">:オブジェクト</param>
    /// <param name="deltaTime">:デルタタイム</param>
    void AddMotionTime(class ObjBase* obj, const float deltaTime);

    /// <summary>
    /// モーション再生
    /// </summary>
    /// <param name="obj">:オブジェクト</param>
    /// <param name="handle">:ハンドル</param>
    void StartMotion(class ObjBase* obj, int handle);

    /// <summary>
    /// モーション停止
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    void StopMotion(int handle);

    /// <summary>
    /// 再生判定
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    /// <returns>再生中:true|停止中:false</returns>
    bool IsPlaying(int handle);

private:
    /// <summary>
    /// ハンドル追加
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(std::string fileName) override;

    /// <summary>
    /// データ追加
    /// </summary>
    /// <param name="key">:jsonデータ取得キー</param>
    void AddData(const rapidjson::Value& key);

    /// <summary>
    /// ハンドル削除
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
        float nowMotionTime;        //現在のモーション時間
        float totalTime;            //総再生時間
    };

    int modelHandle;                                    //モデルハンドル

    std::unordered_map<ObjBase*, int> nowHandle;         //現在のハンドル
    std::unordered_map<int, MotionParam> motionData;    //モーションデータ
    std::unordered_map<int, int> attachedIndex;         //アタッチ後のインデックスデータ
};

