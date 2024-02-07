#include<DxLib.h>

#include"../../KeyStatus/KeyStatus.h"
#include"../SceneBase/SceneBase.h"
#include "Clear.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Collision/CollisionManager/CollisionManager.h"
#include"../../Object/CharaObj/ClearEnemy/ClearEnemy.h"
#include"../Title/Title.h"
#include"../../Object/Camera/FixedCamera/FixedCamera.h"
#include"../../Object/CharaObj/Ball/Ball.h"
#include"../../Object/StageObj/StageManager/StageManager.h"
#include"../../Object/StageObj/Wall/Wall.h"
#include"../../Object/StageObj/Aisle/Aisle.h"
#include"../../GameSystem/Window/Window.h"

Clear::Clear()
    :SceneBase(SceneTag.CLEAR)
{

    for (int i = 0; i < stage.size(); i++)
    {
        for (int j = 0; j < stage[i].size(); j++)
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
    ObjManager::AddObj(new ClearEnemy);
    ObjManager::AddObj(new FixedCamera(VGet(0, BLOCK_SIZE, BLOCK_SIZE*2), VGet(1, 0, 0)));
    ObjManager::AddObj(new Ball);

    backGraph = AssetManager::GraphInstance()->GetHandle(AssetManager::GraphInstance()->
        GetJsonData()[scaneTag.c_str()][scaneTag.c_str()].GetString());
    SetLightEnable(true);
}

Clear::~Clear()
{
    SetLightEnable(false);
}

SceneBase* Clear::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    ObjManager::UpdateObj(deltaTime);
    CollisionManager::CheckCollisionPair();


    //シーン切り替え
    if (KeyStatus::KeyStateDecision(KEY_INPUT_SPACE, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        CollisionManager::DeleteCollision();
        return new Title;
    }

    return this;
}

void Clear::DrawScene()
{
    //オブジェクト描画
    ObjManager::DrawObj();

    DrawExtendGraph(Window::GetWindowSize().x/2-300, Window::GetWindowSize().y -200,
        Window::GetWindowSize().x / 2 + 300, Window::GetWindowSize().y - 50, backGraph, true);
}
