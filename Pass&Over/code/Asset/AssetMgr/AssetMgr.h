#pragma once
#include<memory>

/*AssetMgrクラス*/
class AssetMgr final
{
public:
    /// <summary>
    /// アセットマネージャー初期化処理
    /// </summary>
    static void InitAssetMgr();

    /// <summary>
    /// モデルインスタンス
    /// </summary>
    /// <returns>Modelクラス</returns>
    static class Model* ModelInstance() { return assetMgr->model.get(); }

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~AssetMgr();

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    AssetMgr();

    static std::unique_ptr<AssetMgr> assetMgr;      //自身の実体

    std::unique_ptr<class Model> model;             //モデル
};

