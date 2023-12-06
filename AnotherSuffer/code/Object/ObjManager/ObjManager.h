#pragma once
#include<memory>
#include<vector>
#include<unordered_map>
#include<algorithm>

/// <summary>
/// オブジェクト管理
/// </summary>
class ObjManager final
{
public:
    /// <summary>
    /// オブジェクトマネージャー初期化処理
    /// </summary>
    static void InitObjManager();

    /// <summary>
    /// オブジェクト追加処理
    /// </summary>
    /// <param name="newObj">:追加オブジェクト</param>
    static void AddObj(ObjBase* newObj);

    /// <summary>
    /// オブジェクト更新処理
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    static void UpdateObj(const float deltaTime);

    /// <summary>
    /// オブジェクト描画
    /// </summary>
    static void DrawObj();


    /// <summary>
    /// 全オブジェクト削除処理
    /// </summary>
    static void DeleteAllObj();

    /// <summary>
    /// オブジェクト取得処理
    /// </summary>
    /// <param name="tag">:タグ</param>
    /// <returns>:オブジェクトの配列</returns>
    static std::vector<std::shared_ptr<ObjBase>> GetObj(std::string tag);

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
    /// オブジェクト死亡処理
    /// </summary>
    static void OnDeadObj();

    /// <summary>
    /// オブジェクト削除処理
    /// </summary>
    /// <param name="unnecObj">:不必要オブジェクト</param>
    static void DeleteObj(std::shared_ptr<ObjBase> unnecObj);

    static std::unique_ptr<ObjManager> singleton;       //自身の実体

    std::unordered_map<std::string, std::vector<
        std::shared_ptr<ObjBase>>> object;              //オブジェクト
};

