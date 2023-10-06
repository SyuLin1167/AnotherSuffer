#pragma once
#include<memory>

/*GameSettingクラス*/
class GameSetting final
{
public:
    /// <summary>
    /// 初期化処理
    /// </summary>
    static void Init();

    /// <summary>
    /// ライブラリ初期化前処理
    /// </summary>
    static void BeforeLibInit();

    /// <summary>
    /// ライブラリ初期化後処理
    /// </summary>
    static void AfterLibInit();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameSetting();

private:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameSetting();

    static std::unique_ptr<GameSetting> singleton;     //自身の実体
};

