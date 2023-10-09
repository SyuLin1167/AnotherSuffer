#include "Window.h"

std::unique_ptr<Window> Window::singleton = nullptr;

// 初期化処理 //

void Window::Init()
{
    if (!singleton)
    {
        singleton.reset(new Window);
    }
}

// コンストラクタ //

Window::Window()
{
    //ウィンドウの設定
    ChangeWindowMode(true);
    SetGraphMode(WINDOW_SIZE.x, WINDOW_SIZE.y, COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Pass&Over");
}

// デストラクタ //

Window::~Window()
{
    //処理なし
}