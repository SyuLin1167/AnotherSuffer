#pragma once
#include"../StageObjBase/StageObjBase.h"

/// <summary>
/// 障壁
/// </summary>
class Barricade final:public StageObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="pos">:座標</param>
    Barricade(const VECTOR pos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Barricade();
};

