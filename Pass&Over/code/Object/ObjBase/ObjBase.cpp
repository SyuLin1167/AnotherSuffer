#include"ObjTag.h"
#include "ObjBase.h"

// コンストラクタ //

ObjBase::ObjBase(ObjTag tag)
    :objTag(tag)
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