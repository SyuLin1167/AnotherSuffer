#pragma once

/// <summary>
/// クリア画面
/// </summary>
class Clear:public SceneBase
{
public :
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Clear();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Clear();

private:
    /// <summary>
    /// シーン更新
    /// </summary>
    /// <param name="deltaTime">:フレームレート</param>
    /// <returns>次フレームのシーン</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// シーン描画
    /// </summary>
    void DrawScene() override;

    const std::vector<std::vector<int>> stage
    {
        {1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1},
    };

    int backGraph;
};

