#include "Wall.h"
#include"../../ObjManager/ObjManager.h"

Wall::Wall(const VECTOR pos)
    :StageObjBase(pos)
{
    //�e�N�X�`���\�芷��
    texHandle = AssetManager::GraphInstance()->GetHandle(graphData[jsondata::objKey.wall.c_str()].GetString());
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Wall::~Wall()
{
    //�����Ȃ�
}