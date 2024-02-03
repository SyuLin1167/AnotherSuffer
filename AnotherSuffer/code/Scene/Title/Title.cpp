#include<DxLib.h>
#include<stack>

#include"../../KeyStatus/KeyStatus.h"
#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Collision/CollisionManager/CollisionManager.h"
#include"../../Object/Camera/TitleCamera/TitleCamera.h"
#include"../../Object/CharaObj/Ball/Ball.h"
#include"../../Object/CharaObj/TitleEnemy/TitleEnemy.h"
#include"../../Object/StageObj/StageManager/StageManager.h"
#include"../../Object/StageObj/Wall/Wall.h"
#include"../../Object/StageObj/Aisle/Aisle.h"
#include "Title.h"

static const int MOVEGRAPH_POS_X = 800;
static const int MOVEGRAPH_POS_Y = 800;
static const int MOVEGRAPH_SIZE_X = 300;
static const int MOVEGRAPH_SIZE_Y = 100;

Title::Title()
    :SceneBase(SceneTag.TITLE)
{
    ObjManager::AddObj(new TitleCamera);
    ObjManager::AddObj(new Ball);
    ObjManager::AddObj(new TitleEnemy);
    for (int i = 0; i < stage.size(); i++)
    {
        for (int j=0; j<stage[i].size(); j++)
        {
            if (stage[j][i] & 1)
            {
                ObjManager::AddObj(new Wall(VGet(j * BLOCK_SIZE - BLOCK_SIZE, 0, i * BLOCK_SIZE - BLOCK_SIZE)));
            }
            else
            {
                ObjManager::AddObj(new Aisle(VGet(j * BLOCK_SIZE - BLOCK_SIZE, 0, i * BLOCK_SIZE - BLOCK_SIZE)));
            }
        }
    }
    vert[0].pos = VGet(BLOCK_SIZE/2+BLOCK_SIZE,2, BLOCK_SIZE/2);
    vert[0].norm = VGet(0, 1, 0);
    vert[0].dif = GetColorU8(255, 255, 255, 0);
    vert[0].spc = GetColorU8(0, 0, 0, 0);
    vert[0].u = vert[0].v = 0.0f;
    vert[0].su = vert[0].sv = 0.0f;

    vert[1].pos = VGet(BLOCK_SIZE/2 + BLOCK_SIZE, 2, -BLOCK_SIZE/2);
    vert[1].norm = VGet(0, 1, 0);
    vert[1].dif = GetColorU8(255, 255, 255, 0);
    vert[1].spc = GetColorU8(0, 0, 0, 0);
    vert[1].u = 1.0;
    vert[1].v = 0.0f;
    vert[1].su = vert[1].sv = 0.0f;

    vert[2].pos = VGet(-BLOCK_SIZE/2 + BLOCK_SIZE, 2, BLOCK_SIZE/2);
    vert[2].norm = VGet(0, 1, 0);
    vert[2].dif = GetColorU8(255, 255, 255, 0);
    vert[2].spc = GetColorU8(0, 0, 0, 0);
    vert[2].u = 0.0f;
    vert[2].v = 1.0f;
    vert[2].su = vert[2].sv = 0.0f;

    vert[3].pos = VGet(-BLOCK_SIZE/2 + BLOCK_SIZE, 2, -BLOCK_SIZE/2);
    vert[3].norm = VGet(0, 1, 0);
    vert[3].dif = GetColorU8(255, 255, 255, 0);
    vert[3].spc = GetColorU8(0, 0, 0, 0);
    vert[3].u = vert[3].v = 1.0f;
    vert[3].su = vert[3].sv = 0.0f;

    titleGraph = AssetManager::GraphInstance()->GetHandle(AssetManager::GraphInstance()->
        GetJsonData()[scaneTag.c_str()][scaneTag.c_str()].GetString());
     playGraph= AssetManager::GraphInstance()->GetHandle(AssetManager::GraphInstance()->
        GetJsonData()[scaneTag.c_str()][jsondata::objKey.play.c_str()].GetString());
    moveGraph= AssetManager::GraphInstance()->GetHandle(AssetManager::GraphInstance()->
        GetJsonData()[scaneTag.c_str()][jsondata::objKey.move.c_str()].GetString());
}

Title::~Title()
{
    //処理なし
}

SceneBase* Title::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    ObjManager::UpdateObj(deltaTime);
    CollisionManager::CheckCollisionPair();
    fadePos = ConvWorldPosToScreenPos(ObjManager::GetObj(ObjTag.BALL, 0)->GetObjPos());
    //シーン切り替え
    if (!ObjManager::GetObj(ObjTag.ENEMY,0))
    {
        ObjManager::DeleteAllObj();
        CollisionManager::DeleteCollision();
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    //オブジェクト描画
    ObjManager::DrawObj();
    DrawExtendGraph(0, 0,900,600,  titleGraph, true);
    DrawPolygonIndexed3D(vert, 4, idx, 2, playGraph, false);
    if (MOVEGRAPH_POS_X<fadePos.x && MOVEGRAPH_POS_Y<fadePos.y &&
        MOVEGRAPH_POS_X + MOVEGRAPH_SIZE_X>fadePos.x && MOVEGRAPH_POS_Y + MOVEGRAPH_SIZE_Y * 4>fadePos.y)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
    }
    DrawExtendGraph(MOVEGRAPH_POS_X, MOVEGRAPH_POS_Y,
        MOVEGRAPH_POS_X + MOVEGRAPH_SIZE_X, MOVEGRAPH_POS_Y + MOVEGRAPH_SIZE_Y, moveGraph, true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

#ifdef _DEBUG
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");

    DrawCircle(static_cast<int>(fadePos.x), static_cast<int>(fadePos.y), 5, GetColor(255, 255, 255));
#endif // _DEBUG

}
