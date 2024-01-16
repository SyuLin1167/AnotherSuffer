#pragma once
#include"../CollisionBase/CollisionBase.h"

/// <summary>
/// 線分当たり判定
/// </summary>
class Line final :public CollisionBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="startPos">:始点</param>
    /// <param name="endPos">:終点</param>
    Line(const VECTOR& startPos, const VECTOR& endPos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Line();

    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="pos">:座標</param>
    void Update(const VECTOR& pos);

    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="pos1">:座標1</param>
    /// <param name="pos2">:座標2</param>
    void Update(const VECTOR& pos1,const VECTOR& pos2);

    /// <summary>
    /// メッシュとの衝突判定
    /// </summary>
    /// <param name="modelHandle">:モデルハンドル</param>
    /// <param name="colInfo">:当たり判定情報</param>
    /// <returns>ぶつかった:true|ぶつかっていない:false</returns>
    bool OnCollisionWithMesh(const int modelHandle);

private:
    VECTOR localStartPos;
    VECTOR worldStartPos;
    VECTOR localEndPos;
    VECTOR worldEndPos;
};

