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
    void SceneUpdate();

    /// <summary>
    /// シーン描画処理
    /// </summary>
    void SceneDraw();

    /// <summary>
    /// シーン切り替え処理
    /// </summary>
    void SceneChange();

private:
    std::shared_ptr<class TimeMgr> timeMgr;                     //タイムマネージャー

    std::stack<std::shared_ptr<class SceneBase>> nowScene;      //現在のシーン
    class SceneBase* tmpScene;                                  //一時的なシーン
};

