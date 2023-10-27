#pragma once
#include <string>

/// <summary>
/// jsonオブジェクト用のキー構造体
/// </summary>
struct JsonObjKey
{
    std::string walk = "walk";
}jsonObjKey;

/// <summary>
/// jsonデータ用のキー構造体
/// </summary>
struct JsonDataKey
{
    std::string pass = "pass";
    std::string loop = "loop";
    std::string speed = "speed";
    std::string type = "type";
    std::string volume = "volume";
}jsonDataKey;