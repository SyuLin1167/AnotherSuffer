#pragma once

/*ObjTag�񋓑�*/
enum class ObjTag:unsigned char
{
    CAMERA,
    PLAYER,
    ENEMY,
};

/*���[�v����p�z��*/
constexpr static ObjTag objTagAll[]{
    ObjTag::CAMERA,
    ObjTag::PLAYER,
    ObjTag::ENEMY,
};