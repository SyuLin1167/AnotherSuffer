#include<DxLib.h>
#include<stack>

#include"../../KeyStatus/KeyStatus.h"
#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Collision/CollisionManager/CollisionManager.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Ball/Ball.h"
#include"../../Object/StageObj/StageManager/StageManager.h"
#include"../../Object/StageObj/Wall/Wall.h"
#include"../../Object/StageObj/Aisle/Aisle.h"
#include "Title.h"

Title::Title()
    :SceneBase()
{
    ObjManager::AddObj(new Camera);

    ObjManager::AddObj(new Ball);
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
    graph = AssetManager::GraphInstance()->GetHandle(AssetManager::GraphInstance()->GetJsonData()["title"]["play"].GetString());
    g = LoadGraph("../assets/ui/texture/test.png");
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

    //シーン切り替え
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
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
    DrawPolygonIndexed3D(vert, 4, idx, 2, graph, false);
    
#ifdef _DEBUG
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
#endif // _DEBUG

    DrawExtendGraph(0, 0,900,600, g, true);
}
