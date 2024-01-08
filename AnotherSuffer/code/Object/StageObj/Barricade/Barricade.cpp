#include "Barricade.h"

Barricade::Barricade(const VECTOR pos)
    :StageObjBase(pos)
{
    //テクスチャ貼り換え
    texHandle = LoadGraph("../assets/model/texture/Barricade.png");
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Barricade::~Barricade()
{
    //処理なし
}

void Barricade::OnCollisionEnter(ObjBase* colObj)
{
}

void Barricade::BreakBarricade()
{

}
