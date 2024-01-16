#include<math.h>

#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Object/StageObj/StageManager/StageManager.h"
#include "Enemy.h"
#include"../../../Collision/Capsule/Capsule.h"
#include"../Astar/Astar.h"

Enemy::Enemy()
    :CharaObjBase(ObjTag.ENEMY)
{
    //ƒ‚ƒfƒ‹“Ç‚Ýž‚Ý
    objHandle = MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(modelData.GetString()));
    objDir = VGet(0, 0, -1);
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

    astar = new Astar;
}

Enemy::~Enemy()
{
    //ˆ—‚È‚µ
}

void Enemy::Update(const float deltaTime)
{
    auto& player= ObjManager::GetObj(ObjTag.PLAYER)[0];

    float nowDistance = 100.0f;
    float distance=0.0f;
    VECTOR satrt={}, goal = {};
    for (auto& rowData : StageManager::GetStageData())
    {
        for (auto& colData : rowData.second)
        {
            distance = abs(colData.second.pos.x- player->GetObjPos().x);
            if (nowDistance > distance)
            {
                nowDistance= distance;
                goal = colData.second.pos;
            }
            else
            {
                break;
            }
        }
    }

    astar->Algorithm();
}

void Enemy::MoveChara(const float deltaTime)
{

}

void Enemy::Draw()
{
    //ƒ‚ƒfƒ‹•`‰æ
    MV1DrawModel(objHandle);
}