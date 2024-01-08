#pragma once
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

    static void AddCol();
    static CollisionBase* GetCol();

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

    static std::unique_ptr<CollisionManager> singleton;   //自身の実体
    rapidjson::Document doc;                            //ドキュメント
};

