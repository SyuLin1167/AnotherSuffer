#include "Wall.h"
#include"../../ObjManager/ObjManager.h"

Wall::Wall(const VECTOR pos)
    :StageObjBase(pos)
{
    //テクスチャ貼り換え
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.wall.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Wall::~Wall()
{
    //処理なし
}