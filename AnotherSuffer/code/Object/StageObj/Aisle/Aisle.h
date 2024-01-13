#pragma once
#include"../../StageObj/StageObjBase/StageObjBase.h"

/// <summary>
/// 地面ブロック
/// </summary>
class Aisle final:public StageObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
     /// <param name="pos">:座標</param>
    Aisle(const VECTOR pos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Aisle();
};

