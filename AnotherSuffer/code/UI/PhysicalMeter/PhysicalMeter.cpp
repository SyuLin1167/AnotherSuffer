#include<DxLib.h>

#include "PhysicalMeter.h"
#include"../../GameSystem/Window/Window.h"

static constexpr float METER_POS_Y = 1000;      //パラメーターY座標
static constexpr int METER_WIDTH = 10;           //パラメータ先端幅
static const COLOR_U8 NOMAL_COLOR = GetColorU8(0, 255, 0, 255);
static const COLOR_U8 TRANS_COLOR = GetColorU8(0, 255, 0, 0);
static constexpr int CHANGE_OFFSET = MAX_PARAM / 255;

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
    , isVisible(true)
{

    for (auto& vertIdx : vert)
    {
        for (auto& vertex : vertIdx)
        {
            vertex.rhw = 1.0f;
            vertex.u = vertex.v = 0.0f;
        }
    }

    //画面左の2ポリゴン
    //左
    vert[0][0].pos = VGet(Window::GetWindowSize().x / 2 - MAX_PARAM,
        METER_POS_Y + METER_WIDTH / 4, 0);
    vert[0][1].pos = VGet(Window::GetWindowSize().x / 2 - MAX_PARAM,
        METER_POS_Y + (METER_WIDTH / 4) * 3, 0);
    vert[0][0].dif = vert[0][1].dif = TRANS_COLOR;

    //右
    vert[0][2].pos = VGet(Window::GetWindowSize().x / 2, METER_POS_Y, 0);
    vert[0][3].pos = VGet(Window::GetWindowSize().x / 2, METER_POS_Y + METER_WIDTH, 0);
    vert[0][2].dif = vert[0][3].dif = NOMAL_COLOR;

    //画面右の2ポリゴン
    //左
    vert[1][0].pos = VGet(Window::GetWindowSize().x / 2, METER_POS_Y, 0);
    vert[1][1].pos = VGet(Window::GetWindowSize().x / 2, METER_POS_Y + METER_WIDTH, 0);
    vert[1][0].dif = vert[1][1].dif = NOMAL_COLOR;

    //右
    vert[1][2].pos = VGet(Window::GetWindowSize().x / 2 + MAX_PARAM,
        METER_POS_Y + METER_WIDTH/4, 0);
    vert[1][3].pos = VGet(Window::GetWindowSize().x / 2 + MAX_PARAM,
        METER_POS_Y + (METER_WIDTH / 4) * 3, 0);
    vert[1][2].dif = vert[1][3].dif = TRANS_COLOR;
}

PhysicalMeter::~PhysicalMeter()
{
    //処理なし
}

void PhysicalMeter::ChangePhysicalParam(float physic)
{
    //体力に合わせて色を変えて両端を縮める
    if (physic <= MAX_PARAM || physic >= 0)
    {
        if (physic == 0)
        {
            singleton->isVisible = false;
        }
        else
        {
            singleton->isVisible = true;

            singleton->vert[0][0].pos.x = Window::GetWindowSize().x / 2 - MAX_PARAM + physic;
            singleton->vert[0][1].pos.x = Window::GetWindowSize().x / 2 - MAX_PARAM + physic;
            singleton->vert[1][2].pos.x = Window::GetWindowSize().x / 2 + MAX_PARAM - physic;
            singleton->vert[1][3].pos.x = Window::GetWindowSize().x / 2 + MAX_PARAM - physic;
            for (auto& vertIdx : singleton->vert)
            {
                for (auto& vertex : vertIdx)
                {
                    if (physic * CHANGE_OFFSET > 0)
                    {
                        vertex.dif.r = physic * CHANGE_OFFSET / 2;
                        vertex.dif.g = NOMAL_COLOR.a - vertex.dif.r;
                    }
                    else
                    {
                        vertex.dif.r = 0;
                        vertex.dif.g = NOMAL_COLOR.a - vertex.dif.r;
                    }
                }
            }
        }
    }

    if (singleton->vert[0][0].pos.x < Window::GetWindowSize().x / 2 - MAX_PARAM)
    {
        singleton->vert[0][0].pos.x = Window::GetWindowSize().x / 2 - MAX_PARAM;
        singleton->vert[0][1].pos.x = Window::GetWindowSize().x / 2 - MAX_PARAM;
        singleton->vert[1][2].pos.x = Window::GetWindowSize().x / 2 + MAX_PARAM;
        singleton->vert[1][3].pos.x = Window::GetWindowSize().x / 2 + MAX_PARAM;
    }
}

void PhysicalMeter::Draw()
{
    if (singleton->isVisible)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
        for (auto& vertIdx : singleton->vert)
        {
            DrawPolygonIndexed2D(vertIdx, 4, singleton->idx, 2, DX_NONE_GRAPH, true);
        }

        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
    }
}


