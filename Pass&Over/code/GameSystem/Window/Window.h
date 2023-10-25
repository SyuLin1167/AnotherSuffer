#pragma once
#include<DxLib.h>
#include<memory>

/// <summary>
/// ウィンドウ
/// </summary>
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

    /// <summary>
    /// ウィンドウサイズ取得処理
    /// </summary>
    /// <returns>ウィンドウサイズ</returns>
    static const VECTOR GetWindowSize() { return singleton->WINDOW_SIZE; }
private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    Window();

    const VECTOR WINDOW_SIZE = VGet(1920, 1080, 0);     //ウィンドウサイズ

    static std::unique_ptr<Window> singleton;           //自身の実体
    const int COLOR_BIT = 16;                           //カラービット
};

