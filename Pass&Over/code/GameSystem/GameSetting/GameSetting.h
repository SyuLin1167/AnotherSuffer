#pragma once
#include<memory>

/// <summary>
/// GameSettingクラス
/// </summary>
class GameSetting final
{
public:
    /// <summary>
    /// 初期化処理
    /// </summary>
    static void Init();


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
    /// ライブラリ初期化前処理
    /// </summary>
    static void BeforeLibInit();

    /// <summary>
    /// ライブラリ初期化後処理
    /// </summary>
    static void AfterLibInit();

    static std::unique_ptr<GameSetting> singleton;     //自身の実体
};

