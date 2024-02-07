#pragma once
#include<memory>

static constexpr int MAX_PARAM = 500;           //�p�����[�^�ő�l

/// <summary>
/// �̗̓o�[
/// </summary>
class PhysicalMeter
{
public:
    /// <summary>
    /// �̗̓o�[������
    /// </summary>
    static void InitPhysicalMeter();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~PhysicalMeter();

    /// <summary>
    /// �̗͕ϓ�
    /// </summary>
    /// <param name="physic">:�̗�</param>
    static void ChangePhysicalParam(float physic);

    /// <summary>
    /// �`��
    /// </summary>
    static void Draw();

    /// <summary>
    /// ������Ԏ擾
    /// </summary>
    /// <returns>��:true|�s��:false</returns>
    static bool IsVisible() { return singleton->isVisible; }

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    PhysicalMeter();

    static std::unique_ptr<PhysicalMeter> singleton;        //���g�̎���

    VERTEX2D vert[2][4];
    WORD idx[6] = { 0,1,2,3,2,1 };

    bool isVisible;
};

