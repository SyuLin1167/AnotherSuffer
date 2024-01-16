#include<math.h>
#include<stack>

#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Object/StageObj/StageManager/StageManager.h"
#include "Enemy.h"
#include"../../../Collision/Capsule/Capsule.h"
#include"../../../Collision/Line/Line.h"
#include"../Astar/Astar.h"

Enemy::Enemy()
    :CharaObjBase(ObjTag.ENEMY)
{
    //モデル読み込み
    objHandle = MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(modelData.GetString()));
    objDir = VGet(0, 0, -1);

    astar = new Astar;

    auto stage=StageManager::GetStageData();
    objLocalPos = stage[15][15].pos;
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

    //当たり判定はカプセル型
    capsule = new Capsule(VAdd(objPos, VGet(0, 6, 0)), VAdd(objPos, VGet(0, 30, 0)), 6.0f);
    CollisionManager::AddCol(this, capsule);
    line = new Line(VAdd(objPos, VGet(0, 0, 0)), VAdd(objPos, VGet(0, 0, 0)));
    CollisionManager::AddCol(this, line);

    player = ObjManager::GetObj(ObjTag.PLAYER)[0];

    ResetNode(objPos, &start);
    ResetNode(player->GetObjPos(), &goal);
    path = astar->Algorithm(start, goal);

}

Enemy::~Enemy()
{
    //処理なし
}

void Enemy::Update(const float deltaTime)
{
    if (!path.empty())
    {
        auto stage = StageManager::GetStageData();
        for (auto& point : path)
        {
            float dis = abs(VSize(VSub(stage[point.first][point.second].pos, objPos)));
            if (dis > 5.0f)
            {
                VECTOR vec = VNorm(VSub(stage[point.first][point.second].pos, objPos));
                objLocalPos = VAdd(objLocalPos, VScale(vec, 1.5f));
                rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, vec));
                break;
            }
            else
            {
                path.erase(path.begin());
            }
        }
    }

    //座標更新
    CalcObjPos();
    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Enemy::MoveChara(const float deltaTime)
{

}

void Enemy::OnCollisionEnter(ObjBase* colObj)
{
    //当たり判定処理
    for (auto& obj : CollisionManager::GetCol(colObj))
    {
        if (obj->GetColTag() == ColTag.MODEL)
        {
            //if (capsule->OnCollisionWithMesh(obj->GetColModel()))
            //{
            //    objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh());

            //    MV1CollResultPolyDimTerminate(capsule->GetColInfoDim());
            //}
            if (line->OnCollisionWithMesh(obj->GetColModel()) && path.empty())
            {
                ResetNode(objPos, &start);
                ResetNode(player->GetObjPos(), &goal);
                path = astar->Algorithm(start, goal);
            }
        }
    }

    //座標更新
    //CalcObjPos();
    capsule->Update(objPos);
    line->Update(objPos, player->GetObjPos());

    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Enemy::ResetNode(VECTOR pos, std::pair<int, int>* node)
{
    float nowDistance = 1000.0f;
    float distance = 0.0f;
    for (auto& rowData : StageManager::GetStageData())
    {
        distance = abs(rowData.second[0].pos.z - pos.x);
        if (nowDistance > distance)
        {
            nowDistance = distance;
            node->first = rowData.first;
        }
        else
        {
            nowDistance = 1000.0f;
            for (auto& colData : rowData.second)
            {
                distance = abs(colData.second.pos.x - pos.z);
                if (nowDistance > distance)
                {
                    nowDistance = distance;
                    node->second = colData.first;
                }
                else
                {
                    break;
                }
            }
            break;
        }
    }
}

void Enemy::Draw()
{
    //モデル描画
    MV1DrawModel(objHandle);

#ifdef _DEBUG
    if (path.empty()) {
        DrawFormatString(0, 50, GetColor(255, 255, 255), "ゴールに到達できませんでした。");
    }
    else {
        DrawFormatString(0, 100, GetColor(255, 255, 255), "最短経路: ");
        for (const auto& point : path) {
            DrawFormatString(point.second * 50, point.first * 50 + 200, GetColor(255, 255, 255), "(%d,%d)", point.first, point.second);
        }
    }
#endif // _DEBUG
}