#include "Window.h"

std::unique_ptr<Window> Window::singleton = nullptr;

/// <summary>
/// ����������
/// </summary>
void Window::Init()
{
    if (!singleton)
    {
        singleton.reset(new Window);
    }
}

/// <summary>
/// �R���X�g���N�^(�V���O���g��)
/// </summary>
Window::Window()
{
    //�E�B���h�E�̐ݒ�
    ChangeWindowMode(true);
    SetGraphMode(WINDOW_SIZE.x, WINDOW_SIZE.y, COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Pass&Over");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Window::~Window()
{
    //�����Ȃ�
}