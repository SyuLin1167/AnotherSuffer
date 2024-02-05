#pragma once
#include"../CollisionBase/CollisionBase.h"

class ColModel final:public CollisionBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    ColModel(int& handle);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ColModel();

    /// <summary>
    /// カプセルとの衝突判定
    /// </summary>
    /// <param name="startPos">:始点</param>
    /// <param name="coendPos">:終点</param>
    /// <param name="radius">:半径</param>
    /// <returns>衝突:true|未衝突:false</returns>
    bool OnCollisionWithCapsule(const VECTOR startPos, const VECTOR endPos,const float radius);
};

