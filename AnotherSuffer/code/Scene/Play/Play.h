#pragma once

/// <summary>
/// プレイシーン
/// </summary>
class Play:public SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Play();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Play();

private:
    /// <summary>
    /// シーン更新処理
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    /// <returns>次フレームのシーン</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// シーン描画処理
    /// </summary>
    void DrawScene() override;

    const int CELL_SIZE = 20; // セルのサイズ
    const int MAZE_WIDTH = 16;
    const int MAZE_HEIGHT = 16;

    int maze[16][16];

    void InitializeMaze();

    void GenerateMaze(int x, int y);

    void DrawMaze();
};

