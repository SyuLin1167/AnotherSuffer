#include"../../Object/ObjManager/ObjManager.h"
#include "MiniMap.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../../Object/StageObj/StageManager/StageManager.h"
#include"../../Object/CharaObj/Player/Player.h"

static constexpr int BOX_OFFSET_POSX = 820;         //差分座標X
static constexpr int BOX_OFFSET_POSY = 400;         //差分座標Y
static constexpr int BOX_SIZE = 20;                 //ボックスサイズ

std::unique_ptr<MiniMap> MiniMap::singleton = nullptr;

MiniMap::MiniMap()
    :isVisible(false)
{
   stage = ObjManager::GetObjData(ObjTag.STAGE);
   player = ObjManager::GetObj(ObjTag.PLAYER, 0);
}

void MiniMap::InitMiniMap()
{
    if (!singleton)
    {
        singleton.reset(new MiniMap);
    }
}

MiniMap::~MiniMap()
{
    singleton->mapData.clear();
}

void MiniMap::AddMapData(VECTOR& pos, unsigned int& color)
{
    MiniMapData miniMap{};
    miniMap.pos = pos;
    miniMap.color = color;
    singleton->mapData.push_back(miniMap);
}

void MiniMap::Update()
{
    if (KeyStatus::KeyStateDecision(KEY_INPUT_SPACE, (ONINPUT | NOWONINPUT)))
    {
        singleton->isVisible = true;
    }
    else
    {
        singleton->isVisible = false;
    }
}

void MiniMap::Draw()
{
    if (singleton->isVisible)
    {
        DrawBox(799, 379, 1141, 721, GetColor(0, 255, 255), false);
        for (auto& data : singleton->mapData)
        {
            DrawBox(data.pos.z / 2 + BOX_OFFSET_POSX, data.pos.x / 2 + BOX_OFFSET_POSY, 
                data.pos.z / 2 + BOX_OFFSET_POSX+BOX_SIZE, data.pos.x / 2 + BOX_OFFSET_POSY+ BOX_SIZE, data.color, true);
        }
        DrawCircle(static_cast<int>(singleton->player->GetObjPos().z + 60) / 2+ BOX_OFFSET_POSX - BOX_SIZE, 
            static_cast<int>(singleton->player->GetObjPos().x + 60) / 2+ BOX_OFFSET_POSY - BOX_SIZE, 5, GetColor(255, 255, 255));
    }
    singleton->mapData.clear();
}

MiniMap::MiniMapData::MiniMapData()
    :pos()
    , color()
{
    //処理なし
}

