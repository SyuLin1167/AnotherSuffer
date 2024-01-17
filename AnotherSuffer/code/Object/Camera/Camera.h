#pragma once
#include"../ObjBase/ObjBase.h"

/// <summary>
/// Camera�N���X
/// </summary>
class Camera final:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Camera();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Camera();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    std::shared_ptr<ObjBase> player;            //�v���C���[
    int handle;

    float rotRad;                               //��]�p
    float rotAngle;                             //��]����

    //// �O�p�֐����g�p���A�~�̈ʒu������o���B
    //float add_x = cos(radius) * enemy.m_Length;
    //float add_y = sin(radius) * enemy.m_Length;

    //// ���ʂłł��ʒu�𒆐S�ʒu�ɉ��Z���A�����`��ʒu�Ƃ���
    //enemy.m_PosX = enemy.m_CenterX + add_x;
    //enemy.m_PosY = enemy.m_CenterY + add_y;
};

