#include "Barricade.h"
#include"../../../KeyStatus/KeyStatus.h"
#include"../../../Object/ObjManager/ObjManager.h"
#include"../StageManager/StageManager.h"
#include"../Aisle/Aisle.h"
#include"../../../UI/MousePoint/MousePoint.h"
#include"../../Camera/FirstPersonView/FirstPersonView.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/ColModel/ColModel.h"

Barricade::Barricade(const VECTOR pos, std::pair<int, int> node)
    :StageObjBase(pos)
    , myNode(node)
{
    MV1SetMaterialEmiColor(objHandle, 0, GetColorF(0.5f, 0, 0.5f, 0.01f));

    //テクスチャ貼り換え
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.barricade.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    color = GetColor(50, 5, 60);

    InitCollision();
}

Barricade::~Barricade()
{
    //処理なし
}

void Barricade::OnCollisionEnter(ObjBase* colObj)
{
    for (auto& obj : CollisionManager::GetCol(colObj))
    {
        //プレイヤーが当たっていたら
        if (colObj->GetTag() == ObjTag.PLAYER)
        {
            if (obj->GetColTag() == ColTag.CAPSULE)
            {
                if (colModel.get()->OnCollisionWithCapsule(obj->GetWorldStartPos(), obj->GetWorldEndPos(), obj->GetRadius() * 1.5f))
                {
                    //破壊可能なら障壁を破壊する
                    if (KeyStatus::KeyStateDecision(KEY_INPUT_SPACE, (UNINPUT | NOWUNINPUT)) &&
                        isVisible)
                    {
                        MousePoint::CanVisible();
                        BreakBarricade();
                    }

                    MV1CollResultPolyDimTerminate(colModel->GetColInfoDim());
                    break;
                }
            }
        }
    }
}

void Barricade::BreakBarricade()
{
    //破壊可能なら左クリックで破壊
    if ((GetMouseInput() & MOUSE_INPUT_LEFT))
    {
        StageManager::ChangeStageData(myNode, AISLE);
        StageManager::CountBarricade();
        ObjManager::AddObj(new Aisle(objPos));
        isAlive = false;
    }
}