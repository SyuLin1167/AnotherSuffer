#include<DxLib.h>
#include<stack>

#include"../../KeyStatus/KeyStatus.h"
#include"../SceneBase/SceneBase.h"
#include"../Play/Play.h"
#include"../../Object/ObjManager/ObjManager.h"
#include"../../Object/CharaObj/Astar/Astar.h"
#include "Title.h"

Title::Title()
    :SceneBase()
{

    //// 5x5の迷路
    //std::vector<std::vector<int>> maze = {
    //    {0, 1, 0, 0, 0},
    //    {0, 1, 0, 1, 0},
    //    {0, 0, 0, 1, 0},
    //    {0, 1, 0, 0, 0},
    //    {0, 0, 0, 1, 0}
    //};

    //std::pair<int, int> start = { 0, 0 };
    //std::pair<int, int> goal = { 4, 4 };

    //a = new Astar;
    //path = a->Algorithm(maze, start, goal);
}

Title::~Title()
{
    //処理なし
}

SceneBase* Title::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    ObjManager::UpdateObj(deltaTime);

    //シーン切り替え
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    //オブジェクト描画
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");

    //if (path.empty()) {
    //    DrawFormatString(0, 50, GetColor(255, 255, 255), "ゴールに到達できませんでした。");
    //}
    //else {
    //    DrawFormatString(0, 100, GetColor(255, 255, 255), "最短経路: ");
    //    for (const auto& point : path) {
    //        DrawFormatString(point.second*50, point.first *50+200, GetColor(255, 255, 255), "(%d,%d)", point.first, point.second);
    //    }
    //}
}
