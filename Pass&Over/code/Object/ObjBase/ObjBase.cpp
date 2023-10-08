#include "ObjBase.h"

// コンストラクタ //

ObjBase::ObjBase(ObjTag tag)
    :objTag(tag)
    , isAlive(true)
    , isVisible(true)
    , objHandle(-1)
    , objPos(VGet(0, 0, 0))
    , objDir(VGet(1, 0, 0))
{
    //処理なし
}

// デストラクタ //

ObjBase::~ObjBase()
{
    //処理なし
}

// オブジェクトタグ取得 //

ObjTag& ObjBase::GetTag()
{
    return objTag;
}