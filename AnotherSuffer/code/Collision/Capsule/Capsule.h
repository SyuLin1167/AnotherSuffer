#pragma once
#include<unordered_map>
#include"../CollisionBase/CollisionBase.h"

/// <summary>
/// カプセル型当たり判定
/// </summary>
class Capsule final:public CollisionBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="startPos">:始点</param>
    /// <param name="endPos">:終点</param>
    /// <param name="rad">:半径</param>
    Capsule(const VECTOR& startPos, const VECTOR& endPos,const float& rad);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Capsule();

    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="pos">:移動座標</param>
    void Update(const VECTOR& pos)override;

    /// <summary>
    /// メッシュとの衝突判定
    /// </summary>
    /// <param name="modelHandle">:モデルハンドル</param>
    /// <returns>衝突:true|未衝突:false</returns>
    bool OnCollisionWithMesh(const int& modelHandle);

    bool OnCollisionWithCapsule(const VECTOR& pos, const VECTOR& pos2, const float& rad);

    /// <summary>
    /// メッシュとの衝突時押し戻し量算出
    /// </summary>
    /// <returns>押し戻し量</returns>
    VECTOR CalcPushBackFromMesh();

    /// <summary>
    /// カプセル描画
    /// </summary>
    void DrawCapsule();
};