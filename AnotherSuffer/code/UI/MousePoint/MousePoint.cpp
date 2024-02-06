#include<DxLib.h>

#include "MousePoint.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../GameSystem/Window/Window.h"

static constexpr int MOUSE_GRAPH_SIZE = 50;     //�}�E�X�摜�T�C�Y

std::unique_ptr<MousePoint> MousePoint::singleton;

void MousePoint::InitMousePoint()
{
    if (!singleton)
    {
        singleton.reset(new MousePoint);
    }
}

MousePoint::~MousePoint()
{
    //�����Ȃ�
}

MousePoint::MousePoint()
    :isVisible(false)
{
    mouseHandle= AssetManager::GraphInstance()->GetHandle(AssetManager::GraphInstance()->
        GetJsonData()[jsondata::objKey.mouse.c_str()][jsondata::objKey.mouse.c_str()].GetString());
}

void MousePoint::Draw()
{
    if (singleton->isVisible)
    {
        DrawExtendGraph(Window::GetWindowSize().x / 2 - MOUSE_GRAPH_SIZE,
            Window::GetWindowSize().y / 2 - MOUSE_GRAPH_SIZE,
            Window::GetWindowSize().x / 2 + MOUSE_GRAPH_SIZE,
            Window::GetWindowSize().y / 2 + MOUSE_GRAPH_SIZE, singleton->mouseHandle, true);
    }
}
