#pragma once
#include<memory>

/// <summary>
/// デルタタイムの管理
/// </summary>
class FPS final
{
public:
    /// <summary>
    /// FPS初期化処理
    /// </summary>
    static void InitFPS();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~FPS();

    /// <summary>
    /// 更新処理
    /// </summary>
    static void Update();

    /// <summary>
    /// デルタタイム取得処理
    /// </summary>
    /// <returns>デルタタイム</returns>
    static const float GetDeltaTime() { return singleton->deltaTime; }

private:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    FPS();

    static std::unique_ptr<FPS> singleton;   //自身の実体

    float nowTime;      //現在の時間
    float prevTime;     //過去の時間
    float deltaTime;    //デルタタイム
};

