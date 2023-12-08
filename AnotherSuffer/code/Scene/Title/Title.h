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
    /// シーン更新処理
    /// </summary>
    /// <param name="deltaTime">:フレームレート</param>
    /// <returns>次フレームのシーン</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// シーン描画処理
    /// </summary>
    void DrawScene() override;

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int CELL_SIZE = 40; // セルのサイズ
    const int MAZE_WIDTH = 30;
    const int MAZE_HEIGHT = 30;

    int maze[640 / 20][480 / 20];

    void InitializeMaze();

    void GenerateMaze(int x, int y);

    void DrawMaze();
};

