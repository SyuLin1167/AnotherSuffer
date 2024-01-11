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
    static const VECTOR GetWindowSize();
private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    Window();

    static std::unique_ptr<Window> singleton;           //自身の実体
};

