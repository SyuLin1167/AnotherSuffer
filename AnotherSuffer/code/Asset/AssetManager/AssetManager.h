#pragma once
#include<memory>

#include"../Graph/Graph.h"
#include"../Model/Model.h"
#include"../Motion/Motion.h"
#include"../Sound/Sound.h"

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
    /// グラフインスタンス
    /// </summary>
    /// <returns>Graphクラス</returns>
    static class Graph* GraphInstance(){return singleton->graph.get(); }

    /// <summary>
    /// モデルインスタンス
    /// </summary>
    /// <returns>Modelクラス</returns>
    static class Model* ModelInstance(){ return singleton->model.get(); }

    /// <summary>
    /// モーションインスタンス
    /// </summary>
    /// <returns>Motionクラス</returns>
    static class Motion* MotionInstance(){ return singleton->motion.get(); }

    /// <summary>
    /// サウンドインスタンス
    /// </summary>
    /// <returns>Soundクラス</returns>
    static class Sound* SoundInstance(){ return singleton->sound.get(); }

    /// <summary>
    /// データ内ファイルパス取得
    /// </summary>
    /// <param name="objData">:取得したいオブジェクトデータ</param>
    /// <returns>ファイルパス</returns>
    static const std::string GetFilePass(const rapidjson::Value& objData)
    {
        return objData[jsondata::dataKey.pass.c_str()].GetString();
    }

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    AssetManager();

    static std::unique_ptr<AssetManager> singleton;      //自身の実体

    std::unique_ptr<class Graph> graph;                           //画像
    std::unique_ptr<class Model> model;                           //モデル
    std::unique_ptr<class Motion> motion;                         //モーション
    std::unique_ptr<class Sound> sound;                           //サウンド
};

