#include "Window.h"

std::unique_ptr<Window> Window::singleton = nullptr;
static const VECTOR WINDOW_SIZE = VGet(1920, 1080, 0);     //�E�B���h�E�T�C�Y
static constexpr int COLOR_BIT = 16;                       //�J���[�r�b�g

void Window::InitWindow()
{
    //�C���X�^���X������
    if (!singleton)
    {
        singleton.reset(new Window);
    }
}

Window::Window()
{
    //�E�B���h�E�̐ݒ�
    ChangeWindowMode(true);
    SetGraphMode(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("AnotherSuffer");
}

Window::~Window()
{
    //�����Ȃ�
}

const VECTOR Window::GetWindowSize()
{
    return WINDOW_SIZE;
}
