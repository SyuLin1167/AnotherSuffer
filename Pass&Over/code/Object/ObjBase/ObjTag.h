#pragma once

/*ObjTag列挙体*/
enum class ObjTag:unsigned char
{
    PLAYER,
    ENEMY,
};

/*ループ制御用配列*/
constexpr static ObjTag objTagAll[]{
    ObjTag::PLAYER,
    ObjTag::ENEMY,
};