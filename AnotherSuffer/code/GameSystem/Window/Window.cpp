#include "Window.h"

std::unique_ptr<Window> Window::singleton = nullptr;
static const VECTOR WINDOW_SIZE = VGet(1920, 1080, 0);     //ウィンドウサイズ
static constexpr int COLOR_BIT = 16;                       //カラービット

void Window::InitWindow()
{
    //インスタンス初期化
    if (!singleton)
    {
        singleton.reset(new Window);
    }
}

Window::Window()
{
    //ウィンドウの設定
    ChangeWindowMode(true);
    SetGraphMode(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("AnotherSuffer");
}

Window::~Window()
{
    //処理なし
}

const VECTOR Window::GetWindowSize()
{
    return WINDOW_SIZE;
}
