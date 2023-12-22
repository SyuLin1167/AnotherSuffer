#pragma once
#include"../../StageObj/StageObjBase/StageObjBase.h"

/// <summary>
/// 壁ブロック
/// </summary>
class Wall final:public StageObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="pos">:座標</param>
    Wall(const VECTOR pos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Wall();
};

