#pragma once
#include<memory>
#include<vector>
#include<unordered_map>
#include<algorithm>

#include"../ObjBase/ObjBase.h"
#include"../ObjBase/ObjTag.h"

/// <summary>
/// オブジェクト管理
/// </summary>
class ObjManager final
{
public:
    /// <summary>
    /// オブジェクトマネージャー初期化
    /// </summary>
    static void InitObjManager();

    /// <summary>
    /// オブジェクト追加
    /// </summary>
    /// <param name="newObj">:追加オブジェクト</param>
    static void AddObj(class ObjBase* newObj);

    /// <summary>
    /// オブジェクト更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    static void UpdateObj(const float deltaTime);

    /// <summary>
    /// オブジェクト描画
    /// </summary>
    static void DrawObj();

    /// <summary>
    /// 全オブジェクト削除
    /// </summary>
    static void DeleteAllObj();

    /// <summary>
    /// オブジェクトデータ取得
    /// </summary>
    /// <param name="tag">:タグ</param>
    /// <returns>:オブジェクトの配列</returns>
    static std::vector<std::shared_ptr<class ObjBase>> GetObjData(std::string tag);

    /// <summary>
    /// オブジェクト取得
    /// </summary>
    /// <param name="tag">:タグ</param>
    /// <param name="num">:番号</param>
    /// <returns>指定のオブジェクト</returns>
    static ObjBase* GetObj(std::string tag, int num);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ObjManager();

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    ObjManager();

    /// <summary>
    /// オブジェクト死亡
    /// </summary>
    static void OnDeadObj();

    /// <summary>
    /// オブジェクト削除
    /// </summary>
    /// <param name="unnecObj">:不必要オブジェクト</param>
    static void DeleteObj(std::shared_ptr<class ObjBase> unnecObj);

    static std::unique_ptr<ObjManager> singleton;       //自身の実体

    std::unordered_map<std::string, std::vector<
        std::shared_ptr<class ObjBase>>> object;              //オブジェクト
};

