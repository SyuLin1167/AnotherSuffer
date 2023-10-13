#pragma once
#include<DxLib.h>
#include<../Rapidjson/istreamwrapper.h>
#include<string.h>
#include<string>

#include"ObjTag.h"
#include"../../Asset/AssetManager/AssetManager.h"

/// <summary>
/// ObjBaseクラス
/// </summary>
class ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ</param>
    ObjBase(ObjTag tag);

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
    ObjTag& GetTag();

    /// <summary>
    /// 生死判定
    /// </summary>
    /// <returns>生:true|死:false</returns>
    bool IsAlive() { return isAlive; }

    /// <summary>
    /// 可視判定
    /// </summary>
    /// <returns>可視:true|不可視:false</returns>
    bool IsVisible() { return isVisible; }

protected:
    ObjTag objTag;      //オブジェクトのタグ

    bool isAlive;       //生存状態
    bool isVisible;     //可視判定

    int objHandle;      //ハンドル
    VECTOR objPos;      //座標
    VECTOR objDir;      //方向
};

