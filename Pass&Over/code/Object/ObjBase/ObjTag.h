#pragma once

/// <summary>
/// ObjTag�񋓑�
/// </summary>
enum class ObjTag:unsigned char
{
    CAMERA,
    PLAYER,
    ENEMY,
};

/// <summary>
/// ���[�v����p�z��
/// </summary>
constexpr static ObjTag objTagAll[]{
    ObjTag::CAMERA,
    ObjTag::PLAYER,
    ObjTag::ENEMY,
};