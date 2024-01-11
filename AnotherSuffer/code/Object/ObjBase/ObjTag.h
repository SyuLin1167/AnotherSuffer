#pragma once
#include<string>
#include<vector>

/// <summary>
/// オブジェクトのタグ
/// </summary>
static struct ObjectTag
{
    std::string CAMERA = "camera";
    std::string PLAYER = "player";
    std::string ENEMY = "enemy";
    std::string STAGE = "stage";
}ObjTag;

/// <summary>
/// ループ制御用
/// </summary>
static std::vector <std::string> objTagAll{
    ObjTag.CAMERA,
    ObjTag.PLAYER,
    ObjTag.ENEMY,
    ObjTag.STAGE,
};