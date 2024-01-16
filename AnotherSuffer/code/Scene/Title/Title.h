#pragma once
#include <DxLib.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <ctime>


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

    //class Astar* a;
    std::vector<std::pair<int, int>> path;
};

