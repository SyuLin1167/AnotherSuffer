#pragma once

/// <summary>
/// ObjTag列挙体
/// </summary>
enum class ObjTag:unsigned char
{
    CAMERA,
    PLAYER,
    ENEMY,
};

/// <summary>
/// ループ制御用配列
/// </summary>
constexpr static ObjTag objTagAll[]{
    ObjTag::CAMERA,
    ObjTag::PLAYER,
    ObjTag::ENEMY,
};