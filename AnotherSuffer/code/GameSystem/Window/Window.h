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
    /// ウィンドウ初期化
    /// </summary>
    static void InitWindow();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Window();

    /// <summary>
    /// ウィンドウサイズ取得
    /// </summary>
    /// <returns>ウィンドウサイズ</returns>
    static const VECTOR GetWindowSize() { return singleton->WINDOW_SIZE; }

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    Window();

    static std::unique_ptr<Window> singleton;           //自身の実体

    const VECTOR WINDOW_SIZE = VGet(1920, 1080, 0);     //ウィンドウサイズ
    const int COLOR_BIT = 16;                           //カラービット
};

