#include<DxLib.h>
#include<time.h>
#include<stack>

#include "StageManager.h"

StageManager::StageManager()
{
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < rows; i++)
    {
        maze.push_back(std::vector<Cell>(cols));
    }
    int start_row = rand() % rows;
    int start_col = rand() % cols;

    generateMaze(maze, 0, 0, rows - 1, cols - 1);
}

StageManager::~StageManager()
{

}

void StageManager::generateMaze(std::vector<std::vector<Cell>>& maze, int startRow, int startCol, int goalRow, int goalCol)
{
    std::stack<std::pair<int, int>> stack;
    stack.push({ startRow, startCol });
    maze[startRow][startCol].visited = true;

    while (!stack.empty()) {
        int row, col;
        std::tie(row, col) = stack.top();
        stack.pop();

        std::vector<std::pair<int, int>> neighbors;
        if (row > 0 && !maze[row - 1][col].visited) neighbors.emplace_back(row - 1, col);
        if (row < rows - 1 && !maze[row + 1][col].visited) neighbors.emplace_back(row + 1, col);
        if (col > 0 && !maze[row][col - 1].visited) neighbors.emplace_back(row, col - 1);
        if (col < cols - 1 && !maze[row][col + 1].visited) neighbors.emplace_back(row, col + 1);

        if (!neighbors.empty()) {
            int nextIndex = rand() % neighbors.size();
            int nextRow, nextCol;
            std::tie(nextRow, nextCol) = neighbors[nextIndex];

            if (nextRow < row) maze[row][col].top = maze[nextRow][nextCol].bottom = false;
            else if (nextRow > row) maze[row][col].bottom = maze[nextRow][nextCol].top = false;
            else if (nextCol < col) maze[row][col].left = maze[nextRow][nextCol].right = false;
            else maze[row][col].right = maze[nextRow][nextCol].left = false;

            maze[nextRow][nextCol].visited = true;
            stack.push({ nextRow, nextCol });
        }
    }

    maze[goalRow][goalCol].top = maze[goalRow][goalCol].bottom = maze[goalRow][goalCol].left = maze[goalRow][goalCol].right = false;
}

void StageManager::drawMaze()
{
    int cellSize = 50, wallWidth = 5;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int x = j * cellSize, y = i * cellSize;

            if (maze[i][j].top) DrawBox(x, y, x + cellSize, y + wallWidth, GetColor(255, 255, 255), TRUE);
            if (maze[i][j].left) DrawBox(x, y, x + wallWidth, y + cellSize, GetColor(255, 255, 255), TRUE);
            if (maze[i][j].right) DrawBox(x + cellSize - wallWidth, y, x + cellSize, y + cellSize, GetColor(255, 255, 255), TRUE);
            if (maze[i][j].bottom) DrawBox(x, y + cellSize - wallWidth, x + cellSize, y + cellSize, GetColor(255, 255, 255), TRUE);
        }
    }
}


