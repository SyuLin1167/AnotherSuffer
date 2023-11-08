#pragma once
#include"../../ObjBase/ObjBase.h"
#include"../../Math/Math.h"

/// <summary>
/// CharaObjBaseクラス
/// </summary>
class CharaObjBase:public ObjBase
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
    /// ピッチ回転処理
    /// </summary>
    /// <param name="aimDir">:目標の向き</param>
    /// <param name="velocity">:角速度</param>
    void RotatePitch(const VECTOR& aimDir, float velocity);

    /// <summary>
    /// 回転方向算出処理
    /// </summary>
    /// <returns>:</returns>
    float CaldRotDir();

    float moveSpeed;                        //移動速度

    const VECTOR FRONT = { 1,0,0 };         //前方
    const VECTOR BACK = { -1,0,0 };         //後方
    const VECTOR LEFT = { 0,0,1 };          //左
    const VECTOR RIGHT = { 0,0,-1 };        //右

    const float PI_RAD = 180;               //180度
    bool nowRotate;                         //回転判定
    float rotRad;                           //角速度のラジアン角
    float pitch;                            //ピッチ(回転)

    const rapidjson::Value& modelData = model->GetJsonData()[objTag.c_str()];      //モデルパスデータ
    const rapidjson::Value& soundData = sound->GetJsonData()[objTag.c_str()];      //サウンドパスデータ
    const rapidjson::Value& motionData = motion->GetJsonData()[objTag.c_str()];     //モーションパスデータ
};

