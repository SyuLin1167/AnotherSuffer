#pragma once
#include<memory>

/// <summary>
/// AssetManagerクラス
/// </summary>
class AssetManager final
{
public:
    /// <summary>
    /// アセットマネージャー初期化処理
    /// </summary>
    static void InitAssetManager();

    /// <summary>
    /// モデルインスタンス
    /// </summary>
    /// <returns>Modelクラス</returns>
    static class Model* ModelInstance() { return assetManager->model.get(); }

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~AssetManager();

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    AssetManager();

    static std::unique_ptr<AssetManager> assetManager;      //自身の実体

    std::unique_ptr<class Model> model;             //モデル
};

