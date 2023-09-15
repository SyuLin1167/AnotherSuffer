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
    virtual ~SceneBase();

    /// <summary>
    /// シーン更新処理
    /// </summary>
    /// <param name="deltaTime">:フレームレート</param>
    /// <returns>次フレームのシーン</returns>
    virtual SceneBase* UpdateScene(const float deltaTime) = 0;

    /// <summary>
    /// シーン描画処理
    /// </summary>
    virtual void DrawScene() = 0;
};

