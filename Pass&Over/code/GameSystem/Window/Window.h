#pragma once
#include<memory>

constexpr int SCREEN_WIDTH = 1920;      //スクリーン幅
constexpr int SCREEN_HEIGHT = 1080;     //スクリーン高さ

/*Windowクラス*/
class Window
{
public:
    /// <summary>
    /// 初期化処理
    /// </summary>
    static void Init();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Window();

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    Window();

    static std::unique_ptr<Window> singleton;      //自身の実体
    const int COLOR_BIT = 16;           //カラービット
};

