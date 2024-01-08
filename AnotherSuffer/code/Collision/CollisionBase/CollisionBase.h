#pragma once

/// <summary>
/// 当たり判定の基底クラス
/// </summary>
class CollisionBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CollisionBase();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CollisionBase();

    /// <summary>
    /// ワールド始点座標取得
    /// </summary>
    /// <returns>ワールド始点座標</returns>
    VECTOR GetWorldStartPos() const { worldStart; }

    /// <summary>
    /// ワールド終点座標取得
    /// </summary>
    /// <returns>ワールド終点座標</returns>
    VECTOR GetWorldEndPos() const { worldEnd; }

    /// <summary>
    /// 半径取得
    /// </summary>
    /// <returns>半径</returns>
    float GetRadius() const { radius; }

protected:
    /// <summary>
    /// 座標更新
    /// </summary>
    /// <param name="pos"></param>
    virtual void Update(const VECTOR& pos);

    VECTOR localStart;       //ローカル始点座標
    VECTOR localEnd;         //ローカル終点座標
    VECTOR worldStart;       //ワールド始点座標
    VECTOR worldEnd;         //ワールド終点座標
    VECTOR worldCenter;      //ワールド中心座標
    float radius;            //半径
};

