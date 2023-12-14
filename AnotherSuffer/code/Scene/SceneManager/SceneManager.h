#pragma once
#include<memory>
#include<stack>

/// <summary>
/// シーン管理
/// </summary>
class SceneManager final
{
public:
    /// <summary>
    /// シーン管理初期化
    /// </summary>
    static void InitSceneManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~SceneManager();

    /// <summary>
    /// ゲームループ
    /// </summary>
    static void GameLoop();

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    SceneManager();

    /// シーン更新
    /// </summary>
    static void UpdateScene();

    /// <summary>
    /// シーン描画
    /// </summary>
    static void DrawScene();

    /// <summary>
    /// シーン切り替え
    /// </summary>
    static void ChangeScene();


    static std::unique_ptr<SceneManager> singleton;           //自身の実体

    std::stack<std::unique_ptr<class SceneBase>> nowScene;      //現在のシーン
    class SceneBase* holdScene;                       //保持シーン
};

