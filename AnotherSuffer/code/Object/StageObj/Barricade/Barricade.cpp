#include "Barricade.h"
#include"../../../KeyStatus/KeyStatus.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/ColModel/ColModel.h"

Barricade::Barricade(const VECTOR pos)
    :StageObjBase(pos)
{
    //�e�N�X�`���\�芷��
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.barricade.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
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
                    MV1CollResultPolyDimTerminate(colModel->GetColInfo());
                    break;
                }
            }
        }
    }
}

void Barricade::BreakBarricade()
{
    //B�L�[�Ŕj��
    if (KeyStatus::KeyStateDecision(KEY_INPUT_B, (ONINPUT | NOWONINPUT)))
    {
        isAlive= false;
    }
}
