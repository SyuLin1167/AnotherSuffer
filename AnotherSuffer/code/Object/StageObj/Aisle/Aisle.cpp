#include "Aisle.h"
#include"../../ObjManager/ObjManager.h"

Aisle::Aisle(const VECTOR pos)
    :StageObjBase(pos)
{
    objScale = VGet(0.2f, 0.01f, 0.2f);
    MV1SetScale(objHandle, objScale);

    //テクスチャ貼り換え
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.aisle.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    color = GetColor(25, 75, 75);
}

Aisle::~Aisle()
{
    //処理なし
}