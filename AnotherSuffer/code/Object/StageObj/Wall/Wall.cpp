#include "Wall.h"
#include"../../ObjManager/ObjManager.h"

Wall::Wall(const VECTOR pos)
    :StageObjBase(pos)
{
    //�e�N�X�`���\�芷��
    texHandle = LoadGraph("../assets/model/texture/Wall.png");
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
}

Wall::~Wall()
{
    //�����Ȃ�
}