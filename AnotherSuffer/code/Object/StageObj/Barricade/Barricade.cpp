#include "Barricade.h"
#include"../../../KeyStatus/KeyStatus.h"
#include"../../../Object/ObjManager/ObjManager.h"
#include"../StageManager/StageManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/ColModel/ColModel.h"
#include"../Aisle/Aisle.h"

Barricade::Barricade(const VECTOR pos, std::pair<int, int> node)
    :StageObjBase(pos)
    , myNode(node)
{
    MV1SetEmiColorScale(objHandle,GetColorF(1.0f,0,1.0f,1.0f));

    //�e�N�X�`���\�芷��
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.barricade.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    color = GetColor(50, 5, 60);

    InitCollision();
}

Barricade::~Barricade()
{
    //�����Ȃ�
}

void Barricade::OnCollisionEnter(ObjBase* colObj)
{
    for (auto& obj : CollisionManager::GetCol(colObj))
    {
        //�v���C���[���������Ă�����
        if (colObj->GetTag() == ObjTag.PLAYER)
        {
            if (obj->GetColTag() == ColTag.CAPSULE)
            {
                if (colModel.get()->OnCollisionWithCapsule(obj->GetWorldStartPos(), obj->GetWorldEndPos(), obj->GetRadius() * 2.0f))
                {
                    //��ǂ�j��
                    BreakBarricade();
                    MV1CollResultPolyDimTerminate(colModel->GetColInfoDim());
                    break;
                }
            }
        }
    }
}

void Barricade::BreakBarricade()
{
    //���g�������Ă����獶�N���b�N�Ŕj��
    if (isVisible && GetMouseInput() & MOUSE_INPUT_LEFT)
    {
        StageManager::ChangeStageData(myNode, AISLE);
        StageManager::CountBarricade();
        ObjManager::AddObj(new Aisle(objPos));
        isAlive = false;
    }
}
