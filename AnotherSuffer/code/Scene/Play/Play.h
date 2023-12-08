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


    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int CELL_SIZE = 20; // セルのサイズ
    const int MAZE_WIDTH = 21;
    const int MAZE_HEIGHT = 21;

    int maze[21][21];

    void InitializeMaze();

    void GenerateMaze(int x, int y);

    void DrawMaze();
};

