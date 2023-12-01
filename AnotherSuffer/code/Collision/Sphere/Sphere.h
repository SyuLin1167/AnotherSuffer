#pragma once

/// <summary>
/// 球体型当たり判定
/// </summary>
class Sphere final
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="centerPos">:中心点</param>
    /// <param name="rad">:半径</param>
    Sphere(const VECTOR& centerPos, float rad);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Sphere();

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

    /// <summary>
    /// メッシュとの衝突時押し戻し量算出
    /// </summary>
    /// <param name="colInfo">:当たり判定情報</param>
    /// <returns>押し戻し量</returns>
    VECTOR CalcPushBackFromMesh(const MV1_COLL_RESULT_POLY_DIM& colInfo);

    /// <summary>
    /// デバッグ用描画
    /// </summary>
    void DrawDebug();
private:
    VECTOR localPos;                  //カプセルのローカル中心座標
    VECTOR worldPos;                  //カプセルのワールド中心座標
    float radius;                     //カプセルの半径
};

