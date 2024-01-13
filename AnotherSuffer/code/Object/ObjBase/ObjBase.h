#pragma once
#include<DxLib.h>
#include<../Rapidjson/rapidjson.h>
#include<../Rapidjson/document.h>
#include<string.h>
#include<string>

#include"ObjTag.h"

/// <summary>
/// オブジェクト基底クラス
/// </summary>
class ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ</param>
    ObjBase(std::string tag);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~ObjBase();

    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    virtual void Update(const float deltaTime) = 0;

    /// <summary>
    /// 当たり判定
    /// </summary>
    /// <param name="colObj">:判定するオブジェクト</param>
    virtual void OnCollisionEnter(ObjBase* colObj) {};

    /// <summary>
    /// 描画
    /// </summary>
    virtual void Draw() = 0;

    /// <summary>
    /// タグ取得
    /// </summary>
    /// <returns>オブジェクトタグ</returns>
    std::string GetTag() const { return objTag; }

    /// <summary>
    /// ハンドル取得
    /// </summary>
    /// <returns></returns>
    int GetObjHandle() const { return objHandle; }

    /// <summary>
    /// 座標取得
    /// </summary>
    /// <returns>座標</returns>
    VECTOR GetObjPos() const { return objPos; }

    /// <summary>
    /// フレーム座標取得
    /// </summary>
    /// <returns>指定のフレーム座標</returns>
    VECTOR GetObjFramePos(int frameIdx) const { return MV1GetFramePosition(objHandle, frameIdx); }

    /// <summary>
    /// 方向取得
    /// </summary>
    /// <returns>方向</returns>
    VECTOR GetObjDir() const { return objDir; }

    /// <summary>
    /// 当たり判定情報取得
    /// </summary>
    /// <returns>:当たり判定情報</returns>
    MV1_COLL_RESULT_POLY_DIM GetColInfo()const { return colInfo; }

    /// <summary>
    /// 生死判定
    /// </summary>
    /// <returns>生:true|死:false</returns>
    bool IsAlive() const { return isAlive; }

    /// <summary>
    /// 可視判定
    /// </summary>
    /// <returns>可視:true|不可視:false</returns>
    bool IsVisible() const { return isVisible; }

protected:
    /// <summary>
    /// オブジェクト座標算出
    /// </summary>
    /// <returns>座標</returns>
    void CalcObjPos();

    std::string objTag;     //オブジェクトのタグ

    bool isAlive;           //生存状態
    bool isVisible;         //可視判定

    int objHandle;          //ハンドル
    //int frameIdx;           //フレームのインデックス番号

    VECTOR objScale;        //オブジェクトの大きさ
    VECTOR objPos;          //座標
    VECTOR objWorldPos;     //ワールド座標
    VECTOR objLocalPos;     //ローカル座標
    VECTOR objDir;          //方向

    MV1_COLL_RESULT_POLY_DIM colInfo;
};

