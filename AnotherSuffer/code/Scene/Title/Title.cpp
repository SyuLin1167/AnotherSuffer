#include<DxLib.h>
#include<stack>

#include"../../KeyStatus/KeyStatus.h"
#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Collision/CollisionManager/CollisionManager.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/StageObj/StageManager/StageManager.h"
#include"../../Object/StageObj/Wall/Wall.h"
#include "Title.h"

Title::Title()
    :SceneBase()
{
    ObjManager::AddObj(new Camera);
    ObjManager::AddObj(new Player);
    for (int i = 0; i < stage.size(); i++)
    {
        for (int j=0; j<stage[i].size(); j++)
        {
            if (stage[j][i] & 1)
            {
                ObjManager::AddObj(new Wall(VGet(j * BLOCK_SIZE - BLOCK_SIZE, 0, i * BLOCK_SIZE - BLOCK_SIZE)));
            }
        }
    }
    stage.clear();
}

Title::~Title()
{
    //�����Ȃ�
}

SceneBase* Title::UpdateScene(const float deltaTime)
{
    //�I�u�W�F�N�g�X�V
    ObjManager::UpdateObj(deltaTime);
    CollisionManager::CheckCollisionPair();

    //�V�[���؂�ւ�
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
    //�I�u�W�F�N�g�`��
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}
