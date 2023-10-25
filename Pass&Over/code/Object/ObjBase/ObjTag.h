#pragma once
#include<string.h>
#include<vector>

/// <summary>
/// オブジェクトのタグ
/// </summary>
static struct ObjectTag
{
    std::string CAMERA = "camera";
    std::string PLAYER = "player";
    std::string ENEMY = "enemy";
}ObjTag;

/// <summary>
/// ループ制御用
/// </summary>
static std::vector <std::string> objTagAll{
    ObjTag.CAMERA,
    ObjTag.PLAYER,
    ObjTag.ENEMY,
};