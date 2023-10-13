#include "Window.h"

std::unique_ptr<Window> Window::singleton = nullptr;

void Window::Init()
{
    if (!singleton)
    {
        singleton.reset(new Window);
    }
}

Window::Window()
{
    //ウィンドウの設定
    ChangeWindowMode(true);
    SetGraphMode(WINDOW_SIZE.x, WINDOW_SIZE.y, COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Pass&Over");
}

Window::~Window()
{
    //処理なし
}