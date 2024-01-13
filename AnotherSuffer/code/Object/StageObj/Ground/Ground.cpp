#include "Ground.h"
#include"../../ObjManager/ObjManager.h"

Ground::Ground(const VECTOR pos)
    :StageObjBase(pos)
{
    //テクスチャ貼り換え
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.ground.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Ground::~Ground()
{
    //処理なし
}