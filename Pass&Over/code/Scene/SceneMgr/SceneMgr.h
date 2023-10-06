#pragma once
#include<memory>
#include<stack>

/*SceneMgrクラス*/
class SceneMgr final
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    SceneMgr();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~SceneMgr();

    /// <summary>
    /// ゲームループ
    /// </summary>
    void GameLoop();

    /// <summary>
    /// シーン更新処理
    /// </summary>
    void UpdateScene();

    /// <summary>
    /// シーン描画処理
    /// </summary>
    void DrawScene();

    /// <summary>
    /// シーン切り替え処理
    /// </summary>
    void ChangeScene();

private:
    std::shared_ptr<class TimeManager> timeManager;                 //タイムマネージャー

    std::stack<std::shared_ptr<class SceneBase>> nowScene;      //現在のシーン
    class SceneBase* tmpScene;                                  //一時的なシーン
};

