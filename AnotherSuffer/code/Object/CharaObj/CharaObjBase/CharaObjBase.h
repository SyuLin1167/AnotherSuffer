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

private:
    /// <summary>
    /// アセットパスデータ取得
    /// </summary>
    /// <param name="asset">:任意のアセット</param>
    rapidjson::Value& GetAssetPathData(class AssetBase* asset);

    /// <summary>
    /// 軸ごとのデータ
    /// </summary>
    struct AxisData
    {
    public:
        /// <summary>
        /// コンストラクタ 
        /// </summary>
        /// <param name="axis">：軸</param>
        /// <param name="obj">:オブジェクト</param>
        /// <param name="rad">:初期角度</param>
        AxisData(std::string axis, CharaObjBase* obj, float rad = 0.0f);

        ~AxisData();

    private:

        void Rotate();

        void RotateToAim(const VECTOR& dir,const float& velocity);
        float CalcRotDir(const float& velocity);

        CharaObjBase* object;
        const std::string axisType;   //軸
        VECTOR aimDir;              //目標方向
        float rotRad;           //回転角
        float rotVel;           //回転量
        MATRIX rotMat;          //回転行列
    };

    std::string xAxis = "xAxis";
    std::string yAxis = "yAxis";
    std::string zAxis = "zAxis";
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
    /// X軸目標方向回転
    /// </summary>
    /// <param name="dir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    void RotateToAimXAxis(const VECTOR dir, float velocity);

    /// <summary>
    /// Z軸回転
    /// </summary>
    /// <param name="dir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    void RotateZAxis(const VECTOR dir, float velocity);

    /// <summary>
    /// Z軸目標方向回転
    /// </summary>
    /// <param name="dir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    void RotateToAimZAxis(const VECTOR dir, float velocity);

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

    AxisData* XAxisData;
    AxisData* YAxisData;
    AxisData* ZAxisData;

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

protected:
    VECTOR aimDir;                          //目標座標
    float rotRad;                           //角速度のラジアン角
    float rotXRad;
    float rotYRad;                          //Y軸ラジアン角
    float rotZRad;
    MATRIX rotYMat;                         //Y軸回転行列
    MATRIX rotXMat;
    MATRIX rotZMat;
};

