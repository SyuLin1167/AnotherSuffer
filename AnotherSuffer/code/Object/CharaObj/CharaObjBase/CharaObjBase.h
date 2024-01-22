#pragma once

/// <summary>
/// CharaObjBaseクラス
/// </summary>
class CharaObjBase :public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ名</param>
    CharaObjBase(std::string tag);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~CharaObjBase();

protected:
    /// <summary>
    /// キャラ動作
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    virtual void MoveChara(const float deltaTime) = 0;

    /// <summary>
    /// Y軸回転
    /// </summary>
    /// <param name="dir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    void RotateYAxis(const VECTOR dir, float velocity);

    /// <summary>
    /// X軸回転
    /// </summary>
    /// <param name="dir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    void RotateXAxis(const VECTOR dir, float velocity);

    /// <summary>
    /// Z軸回転
    /// </summary>
    /// <param name="dir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    void RotateZAxis(const VECTOR dir, float velocity);

    /// <summary>
    /// 回転方向算出
    /// </summary>
    /// <returns>:</returns>
    /// <param name="velocity">:角速度</param>
    float CalcRotDirX(float velocity);

    /// <summary>
    /// 回転方向算出
    /// </summary>
    /// <returns>:</returns>
    /// <param name="velocity">:角速度</param>
    float CalcRotDirY(float velocity);

    /// <summary>
    /// 回転方向算出
    /// </summary>
    /// <returns>:</returns>
    /// <param name="velocity">:角速度</param>
    float CalcRotDirZ(float velocity);

    bool isMove;                            //動作判定
    float moveSpeed;                        //移動速度

    static const float ROTATE_SPEED;        //回転速度
    bool nowRotate;                         //回転判定
    MATRIX rotateXMat;                      //X軸回転行列
    MATRIX rotateYMat;                      //Y軸回転行列
    MATRIX rotateZMat;                      //Z軸回転行列

    const rapidjson::Value& modelData;      //モデルパスデータ
    const rapidjson::Value& soundData;      //サウンドパスデータ
    const rapidjson::Value& motionData;     //モーションパスデータ

private:
    /// <summary>
    /// アセットパスデータ取得
    /// </summary>
    /// <param name="asset">:任意のアセット</param>
    rapidjson::Value& GetAssetPathData(class AssetBase* asset);

    VECTOR aimDir;                          //目標座標
    float rotRad;                           //角速度のラジアン角
    float rotXRad;
    float rotYRad;                          //Y軸ラジアン角
    float rotZRad;
    MATRIX rotYMat;                         //Y軸回転行列
    MATRIX rotXMat;
    MATRIX rotZMat;
};

