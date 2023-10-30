#pragma once
#include<DxLib.h>
#include<memory>

/// <summary>
/// KeyStatus�N���X
/// </summary>
class KeyStatus
{
public:
    /// <summary>
    /// �L�[���͏���������
    /// </summary>
    void CreateInstance();

    /// <summary>
    /// ���͔��菈��
    /// </summary>
    /// <param name="key">:���肵�����L�[</param>
    /// <returns>����:true|������:false</returns>
    bool IsInput(int key);

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
        UNINPUT,
    };

    static std::unique_ptr<KeyStatus> singleton;        //���g�̎���

    int inputState;                                     //���̓X�e�[�^�X
};

