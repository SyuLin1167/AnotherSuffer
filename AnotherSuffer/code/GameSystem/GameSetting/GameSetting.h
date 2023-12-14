#pragma once
#include<memory>

/// <summary>
/// ゲーム設定
/// </summary>
class GameSetting final
{
public:
    /// <summary>
    /// ゲーム設定初期化
    /// </summary>
    static void InitGameSetting();


    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameSetting();

private:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameSetting();

    /// <summary>
    /// ライブラリ初期化前
    /// </summary>
    static void BeforeLibInit();

    /// <summary>
    /// ライブラリ初期化後
    /// </summary>
    static void AfterLibInit();

    static std::unique_ptr<GameSetting> singleton;     //自身の実体
};

