#pragma once
#include"../../ObjBase/ObjBase.h"

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
    /// <param name="deltaTime">:フレームレート</param>
    //virtual void MoveChara(const float deltaTime);

    /// <summary>
    /// キャラ回転処理
    /// </summary>
    /// <param name="speed">:回転速度</param>
    void RotateModel(float speed);

    const rapidjson::Value& modelData = model->GetJsonData()[objTag.c_str()];      //モデルパスデータ
    const rapidjson::Value& soundData = sound->GetJsonData()[objTag.c_str()];      //サウンドパスデータ
    const rapidjson::Value& motionData = motion->GetJsonData()[objTag.c_str()];     //モーションパスデータ
};

