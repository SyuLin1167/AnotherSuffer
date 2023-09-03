#pragma once

/*SceneBaseクラス*/
class SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    SceneBase();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~SceneBase();

    /// <summary>
    /// シーン更新処理
    /// </summary>
    virtual void SceneUpdate() = 0;

    /// <summary>
    /// シーン描画処理
    /// </summary>
    virtual void SceneDraw() = 0;


};

