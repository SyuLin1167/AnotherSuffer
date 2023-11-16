#pragma once
#include"../../ObjBase/ObjBase.h"
#include"../../Math/Math.h"

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
    /// データ内ファイルパス取得処理
    /// </summary>
    /// <param name="objData">:取得したいオブジェクトデータ</param>
    /// <returns>ファイルパス</returns>
    const std::string GetFilePass(const rapidjson::Value& objData) { return objData[jsondata::dataKey.pass.c_str()].GetString(); }

    /// <summary>
    /// キャラ動作処理
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    virtual void MoveChara(const float deltaTime) = 0;

    /// <summary>
    /// Y軸回転処理
    /// </summary>
    /// <param name="aimDir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    void RotateYAxis(const VECTOR aimDir, float velocity);

    /// <summary>
    /// 回転方向算出処理
    /// </summary>
    /// <returns>:</returns>
    /// <param name="aimDir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    float CalcRotDir(const VECTOR aimDir, float velocity);

    bool isMove;                            //動作判定
    float moveSpeed;                        //移動速度

    const VECTOR FRONT = VGet(1, 0, 0);         //前方
    const VECTOR BACK = VGet(-1, 0, 0);         //後方
    const VECTOR LEFT = VGet(0, 0, 1);          //左
    const VECTOR RIGHT = VGet(0, 0, -1);        //右

    const float PI_RAD = 180;               //180度
    const float ROTATE_SPEED = 3.0f;        //回転速度
    bool nowRotate;                         //回転判定
    float rotRad;                           //角速度のラジアン角
    MATRIX rotateMat;                       //回転行列

    const rapidjson::Value& modelData = model->GetJsonData()[objTag.c_str()];      //モデルパスデータ
    const rapidjson::Value& soundData = sound->GetJsonData()[objTag.c_str()];      //サウンドパスデータ
    const rapidjson::Value& motionData = motion->GetJsonData()[objTag.c_str()];     //モーションパスデータ
};

