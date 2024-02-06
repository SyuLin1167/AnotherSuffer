#pragma once
#include<memory>

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
    /// �`��
    /// </summary>
    static void Draw();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    PhysicalMeter();

    static std::unique_ptr<PhysicalMeter> singleton;        //���g�̎���

    VERTEX2D vert[2][4];
    WORD idx[6] = { 0,1,2,3,2,1 };
};

