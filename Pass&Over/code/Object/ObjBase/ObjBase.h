#pragma once
#include<DxLib.h>
#include<../Rapidjson/rapidjson.h>
#include<string.h>
#include<string>

#include"ObjTag.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../Asset/Model/Model.h"
#include"../../Asset/Sound/Sound.h"

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
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    virtual void Update(const float deltaTime) = 0;

    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw() = 0;

    /// <summary>
    /// タグ取得
    /// </summary>
    /// <returns>オブジェクトタグ</returns>
    std::string GetTag() const { return objTag; }

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
    std::string objTag;     //オブジェクトのタグ

    bool isAlive;           //生存状態
    bool isVisible;         //可視判定

    Model* model;           //モデル
    Sound* sound;           //サウンド

    int objHandle;          //ハンドル
    VECTOR objScale;        //オブジェクトの大きさ
    VECTOR objPos;          //座標
    VECTOR objDir;          //方向

};

