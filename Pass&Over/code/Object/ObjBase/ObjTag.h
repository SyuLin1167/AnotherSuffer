#pragma once

/*ObjTag�񋓑�*/
enum class ObjTag:unsigned char
{
    PLAYER,
    ENEMY,
};

/*���[�v����p�z��*/
constexpr static ObjTag objTagAll[]{
    ObjTag::PLAYER,
    ObjTag::ENEMY,
};