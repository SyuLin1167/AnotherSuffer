#pragma once
#include<string>
#include<vector>

/// <summary>
/// �I�u�W�F�N�g�̃^�O
/// </summary>
static struct ObjectTag
{
    std::string CAMERA = "camera";
    std::string PLAYER = "player";
    std::string ENEMY = "enemy";
    std::string STAGE = "stage";
}ObjTag;

/// <summary>
/// ���[�v����p
/// </summary>
static std::vector <std::string> objTagAll{
    ObjTag.CAMERA,
    ObjTag.PLAYER,
    ObjTag.ENEMY,
    ObjTag.STAGE,
};