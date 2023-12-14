#pragma once

#include<unordered_map>
#include<vector>

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
    /// シーン更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    /// <returns>次フレームのシーン</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// シーン描画
    /// </summary>
    void DrawScene() override;

    const int CELL_SIZE = 20; // セルのサイズ
    const int STAGE_SIZE = 17;

    const int UP = 0x0001;     //上
    const int DOWN = 0x0002;  //下
    const int LEFT = 0x0004;     //左
    const int RIGHT = 0x0008;  //右
    std::vector<int> directions = { UP, DOWN, LEFT, RIGHT };

    const int WALL = 0x0001;    //壁
    const int AISLE = 0x0002;   //通路
    const int BARRICADE = 0x0004;    //障壁
    std::unordered_map<int, std::vector<int>> stageData;


    void InitializeMaze();

    void GenerateMaze(int x, int y);

    void DrawMaze();
};

