#pragma once
#include<vector>

/// <summary>
/// ステージの管理
/// </summary>
class StageManager final
{
public:
    StageManager();
    ~StageManager();

private:
    const int rows = 5;
    const int cols = 5;

    struct Cell {
        bool visited, top, bottom, left, right;
        Cell() : visited(false), top(true), bottom(true), left(true), right(true) {}
    };
    std::vector<std::vector<Cell>> maze;

    void generateMaze(std::vector<std::vector<Cell>>& maze, int startRow, int startCol, int goalRow, int goalCol);
    void drawMaze();
};

