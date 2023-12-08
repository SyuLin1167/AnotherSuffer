#pragma once
#include<vector>

/// <summary>
/// ステージの管理
/// </summary>
class StageManager final
{
public:
    ~StageManager();

private:
    StageManager();

    static void CreateMaze();
};

