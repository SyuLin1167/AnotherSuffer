#pragma once
#include <string>

namespace jsondata
{
    /// <summary>
    /// json�I�u�W�F�N�g�p�̃L�[�\����
    /// </summary>
    struct JsonObjKey
    {
        std::string walk = "walk";
    }objKey;

    /// <summary>
    /// json�f�[�^�p�̃L�[�\����
    /// </summary>
    struct JsonDataKey
    {
        std::string pass = "pass";
        std::string loop = "loop";
        std::string speed = "speed";
        std::string type = "type";
        std::string volume = "volume";
    }dataKey;
}