#pragma once
#include <string>

namespace jsondata
{
    /// <summary>
    /// jsonオブジェクト用のキー構造体
    /// </summary>
    static struct JsonObjKey
    {
        std::string nomal = "nomal";
        std::string walk = "walk";
    }objKey;

    /// <summary>
    /// jsonデータ用のキー構造体
    /// </summary>
    static struct JsonDataKey
    {
        std::string pass = "pass";
        std::string loop = "loop";
        std::string speed = "speed";
        std::string type = "type";
        std::string volume = "volume";
    }dataKey;
}