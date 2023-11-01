#pragma once
#include<unordered_map>
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

    const float MAX_COUNT = 1.0f;                       //�ő�J�E���g�l
    const float MIN_COUNT = -1.0f;                      //�ŏ��J�E���g�l
    const float MOMENT_COUNT = 0.001f;                  //�u�ԃJ�E���g�l
    const float DELETE_COUNT = 600.0f;                  //�f�[�^�폜�p�J�E���g

    /// <summary>
    /// �L�[�p�����[�^�[
    /// </summary>
    struct KeyParam
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        KeyParam();

        int inputState;             //���̓X�e�[�^�X
        float inputCount;           //���̓J�E���g
    };

    std::unordered_map<int ,KeyParam> keyData;          //�L�[�f�[�^
};

