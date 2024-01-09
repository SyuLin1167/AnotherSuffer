#pragma once
#include<unordered_map>

#include"../../Object/ObjBase/ObjBase.h"
#include"../CollisionBase/CollisionBase.h"

/// <summary>
/// 当たり判定の管理
/// </summary>
class CollisionManager final
{
public:
    /// <summary>
    /// コリジョンマネージャー初期化
    /// </summary>
    static void InitColManager();

    /// <summary>
    /// 当たり判定追加
    /// </summary>
    /// <param name="col">:当たり判定</param>
    static void AddCol(CollisionBase* col);

    /// <summary>
    /// 当たり判定取得
    /// </summary>
    /// <param name="obj">:オブジェクト</param>
    /// <returns>オブジェクトの当たり判定</returns>
    static CollisionBase* GetCol(ObjBase* obj);

    /// <summary>
    /// 当たり判定組み合わせ判別
    /// </summary>
    static void CheckCollisionPair();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CollisionManager();
private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    CollisionManager();

    /// <summary>
    /// 当たり判定
    /// </summary>
    /// <param name="mainObj">:主オブジェクトタグ</param>
    /// <param name="pairObj">:ペアオブジェクトタグ</param>
    static void OnCollisionEnter(std::string mainObjTag, std::string pairObjTag);

    static std::unique_ptr<CollisionManager> singleton;     //自身の実体
    rapidjson::Document doc;                                //ドキュメント
    std::unordered_map<ObjBase*, CollisionBase*> colData;   //当たり判定データ
};

