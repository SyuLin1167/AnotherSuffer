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

    //// 5x5�̖��H
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
    //�����Ȃ�
}

SceneBase* Title::UpdateScene(const float deltaTime)
{
    //�I�u�W�F�N�g�X�V
    ObjManager::UpdateObj(deltaTime);

    //�V�[���؂�ւ�
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        ObjManager::DeleteAllObj();
        return new Play;
    }

    return this;
}

void Title::DrawScene()
{
    //�I�u�W�F�N�g�`��
    ObjManager::DrawObj();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "title");

    //if (path.empty()) {
    //    DrawFormatString(0, 50, GetColor(255, 255, 255), "�S�[���ɓ��B�ł��܂���ł����B");
    //}
    //else {
    //    DrawFormatString(0, 100, GetColor(255, 255, 255), "�ŒZ�o�H: ");
    //    for (const auto& point : path) {
    //        DrawFormatString(point.second*50, point.first *50+200, GetColor(255, 255, 255), "(%d,%d)", point.first, point.second);
    //    }
    //}
}
