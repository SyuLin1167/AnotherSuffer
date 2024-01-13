#include "Barricade.h"
#include"../../../KeyStatus/KeyStatus.h"
#include"../../../Object/ObjManager/ObjManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/ColModel/ColModel.h"
#include"../Aisle/Aisle.h"

Barricade::Barricade(const VECTOR pos)
    :StageObjBase(pos)
{
    //テクスチャ貼り換え
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.barricade.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    color = GetColor(50, 5, 60);
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
                if (colModel.get()->OnCollisionWithCapsule(obj->GetWorldStartPos(), obj->GetWorldEndPos(), obj->GetRadius() * 2.0f))
                {
                    //障壁を破壊
                    BreakBarricade();
                    MV1CollResultPolyDimTerminate(colModel->GetColInfo());
                    break;
                }
            }
        }
    }
}

void Barricade::BreakBarricade()
{
    //Bキーで破壊
    if (KeyStatus::KeyStateDecision(KEY_INPUT_B, (ONINPUT | NOWONINPUT)))
    {
        ObjManager::AddObj(new Aisle(objPos));
        isAlive= false;
    }
}
