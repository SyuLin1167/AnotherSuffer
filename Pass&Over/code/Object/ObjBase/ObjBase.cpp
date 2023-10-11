#include "ObjBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="tag"></param>
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

/// <summary>
/// デストラクタ
/// </summary>
ObjBase::~ObjBase()
{
    //処理なし
}

/// <summary>
/// オブジェクトタグ取得
/// </summary>
/// <returns>オブジェクトタグ</returns>
ObjTag& ObjBase::GetTag()
{
    return objTag;
}