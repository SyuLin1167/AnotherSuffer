#include "Ground.h"
#include"../../ObjManager/ObjManager.h"

Ground::Ground(const VECTOR pos)
    :StageObjBase(pos)
{
    //�e�N�X�`���\�芷��
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.ground.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Ground::~Ground()
{
    //�����Ȃ�
}