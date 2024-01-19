#pragma once
#include <DxLib.h>
#include <vector>
#include <stack>


/// <summary>
/// タイトルシーン
/// </summary>
class Title final: public SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Title();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Title();

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
        {1,1,1,1,1},
        {1,0,0,1,1},
        {1,0,1,1,1},
        {1,0,0,1,1},
        {1,1,1,1,1},
    };

    VERTEX3D vert[4];
    WORD idx[6] = { 0,1,2,3,2,1 };
    int graph;
    int g;
};

