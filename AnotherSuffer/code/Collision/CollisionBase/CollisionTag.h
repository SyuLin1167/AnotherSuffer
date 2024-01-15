#pragma once
#include<string>

/// <summary>
/// オブジェクトのタグ
/// </summary>
static struct CollisionTag
{
    std::string MODEL = "model";        //モデル
    std::string CAPSULE = "capsule";    //カプセル
    std::string LINE = "line";          //線分
}ColTag;