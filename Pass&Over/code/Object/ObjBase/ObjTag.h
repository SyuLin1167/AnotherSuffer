#pragma once

/*ObjTag列挙体*/
enum class ObjTag:unsigned char
{
    CAMERA,
    PLAYER,
    ENEMY,
};

/*ループ制御用配列*/
constexpr static ObjTag objTagAll[]{
    ObjTag::CAMERA,
    ObjTag::PLAYER,
    ObjTag::ENEMY,
};