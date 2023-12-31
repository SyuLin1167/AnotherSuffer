#pragma once
#include<memory>

/// <summary>
/// アセット管理
/// </summary>
class AssetManager final
{
public:
    /// <summary>
    /// アセットマネージャー初期化
    /// </summary>
    static void InitAssetManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~AssetManager();

    /// <summary>
    /// モデルインスタンス
    /// </summary>
    /// <returns>Modelクラス</returns>
    static class Model* ModelInstance() { return assetManager->model.get(); }

    /// <summary>
    /// モーションインスタンス
    /// </summary>
    /// <returns>Motionクラス</returns>
    static class Motion* MotionInstance() { return assetManager->motion.get(); }

    /// <summary>
    /// サウンドインスタンス
    /// </summary>
    /// <returns>Soundクラス</returns>
    static class Sound* SoundInstance() { return assetManager->sound.get(); }

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    AssetManager();

    static std::unique_ptr<AssetManager> assetManager;      //自身の実体

    std::unique_ptr<class Model> model;                           //モデル
    std::unique_ptr<class Motion> motion;                         //モーション
    std::unique_ptr<class Sound> sound;                           //サウンド
};

