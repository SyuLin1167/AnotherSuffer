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
        AxisData(const std::string& axis, CharaObjBase* obj,const float rad = 0.0f);

        /// <summary>
        /// デストラクタ 
        /// </summary>
        ~AxisData() {};

        /// <summary>
        /// 回転
        /// </summary>
        /// <param name="dir">:目標方向</param>
        /// <param name="velocity">:回転量</param>
        void Rotate(const VECTOR& dir, const float& velocity);

        /// <summary>
        /// 目標方向への回転
        /// </summary>
        /// <param name="dir">:目標方向</param>
        /// <param name="velocity">:回転量</param>
        void RotateToAim(const VECTOR& dir,const float& velocity);

        /// <summary>
        /// 目標方向への直接回転
        /// </summary>
        /// <param name="dir1">:目標方向</param>
        void RotateToAim(const VECTOR& dir);

        /// <summary>
        /// 回転行列取得
        /// </summary>
        /// <returns></returns>
        MATRIX GetRotateMat()const { return rotMat; }
    private:
        /// <summary>
        /// 回転方向算出
        /// </summary>
        /// <param name="velocity">回転量</param>
        /// <returns>回転する向き</returns>
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
    
    std::unique_ptr<AxisData> XAxisData;
    std::unique_ptr<AxisData> YAxisData;
    std::unique_ptr<AxisData> ZAxisData;

    bool isMove;                            //動作判定
    float moveSpeed;                        //移動速度

    static const float ROTATE_SPEED;        //回転速度
    bool nowRotate;                         //回転判定

    const rapidjson::Value& modelData;      //モデルパスデータ
    const rapidjson::Value& soundData;      //サウンドパスデータ
    const rapidjson::Value& motionData;     //モーションパスデータ
};

