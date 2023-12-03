#pragma once
#include<memory>

/// <summary>
/// �f���^�^�C���̊Ǘ�
/// </summary>
class FPS final
{
public:
    /// <summary>
    /// FPS����������
    /// </summary>
    static void InitFPS();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~FPS();

    /// <summary>
    /// �X�V����
    /// </summary>
    static void Update();

    /// <summary>
    /// �f���^�^�C���擾����
    /// </summary>
    /// <returns>�f���^�^�C��</returns>
    static const float GetDeltaTime() { return singleton->deltaTime; }

private:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    FPS();

    static std::unique_ptr<FPS> singleton;   //���g�̎���

    float nowTime;      //���݂̎���
    float prevTime;     //�ߋ��̎���
    float deltaTime;    //�f���^�^�C��
};

