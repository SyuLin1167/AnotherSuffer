#include "ObjBase.h"

// コンストラクタ //

ObjBase::ObjBase(ObjTag tag)
    :objTag(tag)
    , isAlive(true)
    , objHandle(-1)
    , objPos(VGet(0, 0, 0))
{

}

// デストラクタ //

ObjBase::~ObjBase()
{

}

// オブジェクトタグ取得 //

ObjTag& ObjBase::GetTag()
{
    return objTag;
}