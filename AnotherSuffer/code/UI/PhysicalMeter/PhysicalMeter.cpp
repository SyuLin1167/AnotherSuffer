#include<DxLib.h>

#include "PhysicalMeter.h"
#include"../../GameSystem/Window/Window.h"

std::unique_ptr<PhysicalMeter> PhysicalMeter::singleton;

void PhysicalMeter::InitPhysicalMeter()
{
    if (!singleton)
    {
        singleton.reset(new PhysicalMeter);
    }
}

PhysicalMeter::PhysicalMeter()
    :vert()
{

    for (auto& vertIdx : vert)
    {
        for (auto& vertex : vertIdx)
        {
            vertex.rhw = 1.0f;
            vertex.u = vertex.v = 0.0f;
        }
    }

    vert[0][0].pos = VGet(500, 1000+3, 0);
    vert[0][0].dif = GetColorU8(0, 255, 0, 10);

    vert[0][1].pos = VGet(500, 1000+7, 0);
    vert[0][1].dif = GetColorU8(0, 255, 0, 10);

    vert[0][2].pos = VGet(Window::GetWindowSize().x / 2, 1000, 0);
    vert[0][2].dif = GetColorU8(255, 0, 0, 255);

    vert[0][3].pos = VGet( Window::GetWindowSize().x / 2, 1000 + 10, 0);
    vert[0][3].dif = GetColorU8(255, 0, 0, 255);

    vert[1][0].pos = VGet(Window::GetWindowSize().x / 2, 1000, 0);
    vert[1][0].dif = GetColorU8(255, 0, 0, 255);

    vert[1][1].pos = VGet(Window::GetWindowSize().x / 2, 1000 + 10, 0);
    vert[1][1].dif = GetColorU8(255, 0, 0, 255);

    vert[1][2].pos = VGet(Window::GetWindowSize().x - 500, 1000+3, 0);
    vert[1][2].dif = GetColorU8(0, 255, 0, 10);

    vert[1][3].pos = VGet(Window::GetWindowSize().x - 500, 1000+7, 0);
    vert[1][3].dif = GetColorU8(0, 255, 0, 10);
}

PhysicalMeter::~PhysicalMeter()
{
    //ˆ—‚È‚µ
}

void PhysicalMeter::Draw()
{
    for (auto& vertIdx : singleton->vert)
    {
        DrawPolygonIndexed2D(vertIdx, 4, singleton->idx, 2, DX_NONE_GRAPH, false);
    }
}


