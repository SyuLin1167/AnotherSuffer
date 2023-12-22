#include "Barricade.h"

Barricade::Barricade(const VECTOR pos)
    :StageObjBase(pos)
{
    texHandle = LoadGraph("../assets/model/texture/Barricade.png");
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Barricade::~Barricade()
{
}
