#pragma once
#include"CollisionTag.h"

/// <summary>
/// 当たり判定の基底クラス
/// </summary>
class CollisionBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ</param>
    CollisionBase(std::string tag);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CollisionBase();

    /// <summary>
    /// 当たり判定タグ取得
    /// </summary>
    /// <returns></returns>
    std::string GetColTag() const { return colTag; }

    /// <summary>
    /// モデル取得
    /// </summary>
    /// <returns></returns>
    int GetColModel() const { return colHandle; }

    /// <summary>
    /// 配列型衝突判定情報取得
    /// </summary>
    /// <returns>配列型衝突判定情報</returns>
    MV1_COLL_RESULT_POLY_DIM GetColInfoDim() const { return colInfoDim; }

    /// <summary>
    /// 衝突判定情報取得
    /// </summary>
    /// <returns>衝突判定情報</returns>
    MV1_COLL_RESULT_POLY GetColInfo() const { return colInfo; }

    /// <summary>
    /// ワールド始点座標取得
    /// </summary>
    /// <returns>ワールド始点座標</returns>
    VECTOR GetWorldStartPos() const {return worldStart; }

    /// <summary>
    /// ワールド終点座標取得
    /// </summary>
    /// <returns>ワールド終点座標</returns>
    VECTOR GetWorldEndPos() const {return worldEnd; }

    /// <summary>
    /// 半径取得
    /// </summary>
    /// <returns>半径</returns>
    float GetRadius() const {return radius; }

protected:
    /// <summary>
    /// 座標更新
    /// </summary>
    /// <param name="pos"></param>
    virtual void Update(const VECTOR& pos);

    std::string colTag;                     //当たり判定タグ

    int colHandle;                          //ハンドル
    MV1_COLL_RESULT_POLY_DIM colInfoDim;    //当たり判定情報配列
    MV1_COLL_RESULT_POLY colInfo;           //当たり判定情報

    VECTOR localStart;                      //ローカル始点座標
    VECTOR localEnd;                        //ローカル終点座標
    VECTOR worldStart;                      //ワールド始点座標
    VECTOR worldEnd;                        //ワールド終点座標
    VECTOR worldCenter;                     //ワールド中心座標
    float radius;                           //半径
};

