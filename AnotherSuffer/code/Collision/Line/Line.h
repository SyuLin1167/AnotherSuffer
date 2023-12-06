#pragma once
#include<DxLib.h>

/// <summary>
/// 線分当たり判定
/// </summary>
class Line final
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
    /// 更新処理
    /// </summary>
    /// <param name="pos">:移動座標</param>
    void Update(const VECTOR& pos);

    /// <summary>
    /// メッシュとの衝突判定処理
    /// </summary>
    /// <param name="modelHandle">:モデルハンドル</param>
    /// <param name="colInfo">:当たり判定情報</param>
    /// <returns>ぶつかった:true|ぶつかっていない:false</returns>
    bool OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo);

private:
    VECTOR localStartPos;
    VECTOR worldStartPos;
    VECTOR localEndPos;
    VECTOR worldEndPos;
};

