#pragma once
constexpr int SCREEN_WIDTH = 1920;      //スクリーン幅
constexpr int SCREEN_HEIGHT = 1080;     //スクリーン高さ


/*GameSettingクラス*/
class GameSetting
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameSetting();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameSetting();

    /// <summary>
    /// ライブラリ初期化前処理
    /// </summary>
    void LibInitBefore();

    /// <summary>
    /// ライブラリ初期化後処理
    /// </summary>
    void LibInitAfter();
private:
    const int COLOR_BIT = 16;
};

