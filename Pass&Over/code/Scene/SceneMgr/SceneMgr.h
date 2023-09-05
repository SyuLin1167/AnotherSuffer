#pragma once
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

private:
    std::stack<class SceneBase*> nowScene;      //現在のシーン
    class SceneBase* tmpScene;                        //一時的なシーン
};

