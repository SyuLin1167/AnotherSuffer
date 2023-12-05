#pragma once

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

    const int rows = 5;
    const int cols = 5;

    struct Cell {
        bool visited, top, bottom, left, right;
        Cell() : visited(false), top(true), bottom(true), left(true), right(true) {}
    };
    std::vector<std::vector<Cell>> maze;

    void generateMaze(std::vector<std::vector<Cell>>& maze, int startRow, int startCol, int goalRow, int goalCol);
    void drawMaze(const std::vector<std::vector<Cell>>& maze);
};

