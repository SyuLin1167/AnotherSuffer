#include "Barricade.h"

Barricade::Barricade(const VECTOR pos)
    :StageObjBase(pos)
{
    //�e�N�X�`���\�芷��
    texHandle = LoadGraph("../assets/model/texture/Barricade.png");
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Barricade::~Barricade()
{
    //�����Ȃ�
}

void Barricade::OnCollisionEnter(ObjBase* colObj)
{
}

void Barricade::BreakBarricade()
{

}
