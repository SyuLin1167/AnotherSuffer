#pragma once
#include<memory>

/// <summary>
/// KeyStatus�N���X
/// </summary>
class KeyStatus
{
public:
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~KeyStatus();
private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    KeyStatus();

    /// <summary>
    /// ���͏�Ԏ��
    /// </summary>
    enum class KeyState
    {
        NOMAL=0,
        ONINPUT,
        NOWINPUT,
        AFTERINPUT,
    };

    static std::unique_ptr<KeyStatus> singleton;        //���g�̎���

    int inputState;
};

