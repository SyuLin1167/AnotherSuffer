#pragma once
#include<vector>
#include<memory>

constexpr int UNINPUT = 0x0001;     //�����͎�
constexpr int NOWUNINPUT = 0x0002;  //�����͒�
constexpr int ONINPUT = 0x0004;     //���͎�
constexpr int NOWINPUT = 0x0008;    //���͒�

/// <summary>
/// KeyStatus�N���X
/// </summary>
class KeyStatus final
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
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void KeyStateDecision(int key, float deltaTime);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~KeyStatus();
private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    KeyStatus();

    static std::unique_ptr<KeyStatus> singleton;        //���g�̎���

    const float MAXCOUNT = 1.0f;
    const float MINCOUNT = -1.0f;

    /// <summary>
    /// �L�[�p�����[�^�[
    /// </summary>
    struct KeyParam
    {
    public:
        KeyParam();

        int inputState;             //���̓X�e�[�^�X
        float inputCount;           //���̓J�E���g
    };

    std::vector<KeyParam> keyData;  //�L�[�f�[�^
};

