#pragma once
#include<DxLib.h>
#include<../Rapidjson/istreamwrapper.h>
#include<string.h>
#include<string>

#include"ObjTag.h"
#include"../../Asset/AssetMgr/AssetMgr.h"

/*ObjBaseクラス*/
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
    /// <param name="deltaTime">:フレームレート</param>
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

protected:
    ObjTag objTag;      //オブジェクトのタグ

    bool isAlive;       //生存状態

    int objHandle;      //ハンドル
    VECTOR objPos;    //座標
};

