#pragma once
#include <string>

namespace jsondata
{
    /// <summary>
    /// json�I�u�W�F�N�g�p�̃L�[�\����
    /// </summary>
    static struct JsonObjKey
    {
        std::string nomal = "nomal";
        std::string walk = "walk";
        std::string run = "run";
        std::string look = "look";
        std::string hide = "hide";
        std::string wall = "wall";
        std::string barricade = "barricade";
        std::string aisle = "aisle";
        std::string play = "play";
        std::string move = "move";
        std::string scream = "scream";
        std::string mouse = "mouse";
        std::string dance = "dance";
        std::string clear = "clear";
    }objKey;

    /// <summary>
    /// json�f�[�^�p�̃L�[�\����
    /// </summary>
    static struct JsonDataKey
    {
        std::string pass = "pass";
        std::string bgm = "bgm";
        std::string loop = "loop";
        std::string speed = "speed";
        std::string type = "type";
        std::string volume = "volume";
    }dataKey;
}