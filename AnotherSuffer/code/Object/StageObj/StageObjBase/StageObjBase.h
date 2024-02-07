#pragma once
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// ステージオブジェクトの基底クラス
/// </summary>
class StageObjBase:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="pos">:座標</param>
    StageObjBase(const VECTOR pos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~StageObjBase();

private:
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    /// <summary>
    /// 視野外切り抜き
    /// </summary>
    void ViewClipBox();

    ObjBase* player;        //プレイヤー

protected:
    /// <summary>
    /// 当たり判定初期化
    /// </summary>
    void InitCollision();

    const rapidjson::Value& graphData;      //グラフパスデータ

    VECTOR clipBoxScale;        //切り抜きボックススケール
    VECTOR clipBoxPos1;         //切り抜きボックス座標1
    VECTOR clipBoxPos2;         //切り抜きボックス座標2

    int texHandle;              //テクスチャハンドル
    int texIndex;               //テクスチャインデックス

    unsigned int color;

    std::unique_ptr<class ColModel> colModel;   //当たり判定
};

