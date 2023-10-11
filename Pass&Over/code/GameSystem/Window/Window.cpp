#include "Window.h"

std::unique_ptr<Window> Window::singleton = nullptr;

/// <summary>
/// 初期化処理
/// </summary>
void Window::Init()
{
    if (!singleton)
    {
        singleton.reset(new Window);
    }
}

/// <summary>
/// コンストラクタ(シングルトン)
/// </summary>
Window::Window()
{
    //ウィンドウの設定
    ChangeWindowMode(true);
    SetGraphMode(WINDOW_SIZE.x, WINDOW_SIZE.y, COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Pass&Over");
}

/// <summary>
/// デストラクタ
/// </summary>
Window::~Window()
{
    //処理なし
}