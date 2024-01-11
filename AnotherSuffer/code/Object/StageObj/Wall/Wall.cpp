#include "Wall.h"
#include"../../ObjManager/ObjManager.h"

Wall::Wall(const VECTOR pos)
    :StageObjBase(pos)
{
    //テクスチャ貼り換え
    texHandle = LoadGraph("../assets/model/texture/Wall.png");
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Wall::~Wall()
{
    //処理なし
}