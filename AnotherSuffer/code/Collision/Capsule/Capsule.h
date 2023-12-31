#pragma once
#include<DxLib.h>
#include<unordered_map>

/// <summary>
/// カプセル型当たり判定
/// </summary>
class Capsule final
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="startPos">:始点</param>
    /// <param name="endPos">:終点</param>
    /// <param name="rad">:半径</param>
    Capsule(const VECTOR& startPos, const VECTOR& endPos, float rad);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Capsule();

    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="pos">:移動座標</param>
    void Update(const VECTOR& pos);

    /// <summary>
    /// メッシュとの衝突判定
    /// </summary>
    /// <param name="modelHandle">:モデルハンドル</param>
    /// <param name="colInfo">:当たり判定情報</param>
    /// <returns>ぶつかった:true|ぶつかっていない:false</returns>
    bool OnCollisionWithMesh(const int modelHandle, MV1_COLL_RESULT_POLY_DIM& colInfo);

    /// <summary>
    /// メッシュとの衝突時押し戻し量算出
    /// </summary>
    /// <param name="colInfo">:当たり判定情報</param>
    /// <returns>押し戻し量</returns>
    VECTOR CalcPushBackFromMesh(MV1_COLL_RESULT_POLY_DIM& colInfo);
    /// <summary>
    /// カプセル描画
    /// </summary>
    void DrawCapsule();

private:
    VECTOR localStart;                  //カプセルのローカル座標始点
    VECTOR localEnd;                    //カプセルのローカル座標終点
    VECTOR worldStart;                  //カプセルのワールド座標始点
    VECTOR worldEnd;                    //カプセルのワールド座標終点
    VECTOR worldCenter;                 //カプセルのワールド中心座標
    float radius;                       //カプセルの半径
};