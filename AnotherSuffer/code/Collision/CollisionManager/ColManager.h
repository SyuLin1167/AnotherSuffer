#pragma once
#include"../../Object/ObjBase/ObjBase.h"

/// <summary>
/// 当たり判定の管理
/// </summary>
class ColManager
{
public:
    /// <summary>
    /// コリジョンマネージャー初期化
    /// </summary>
    static void InitColManager();

    /// <summary>
    /// 当たり判定組み合わせ判別
    /// </summary>
    static void CheckCollisionPair();

    /// <summary>
    /// 当たり判定
    /// </summary>
    static void OnCollisionEnter();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ColManager();
private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    ColManager();

    static std::unique_ptr<ColManager> singleton;   //自身の実体
    rapidjson::Document doc;                            //ドキュメント
};

