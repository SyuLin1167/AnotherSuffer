#pragma once
#include"../../ObjBase/ObjBase.h"

constexpr float CAMERA_NEAR = 0.1f;
constexpr float CAMERA_FAR = 500.0f;

/// <summary>
/// ��l�̎��_
/// </summary>
class FirstPersonView final:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    FirstPersonView();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~FirstPersonView();

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// ���_�̈ړ��ʎZ�o
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void CalcMoveView(const float deltaTime);

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw() override;

private:
    int mousePosX;                              //�}�E�X���WX
    int mousePosY;                              //�}�E�X���WY
    VECTOR angleVel;                            //�ړ���

    const VECTOR ANGLE_POS = VGet(0, 20, 0);    //���_���W

    const float MAX_PITCH = 1.0f;               //�s�b�`�}�b�N�X�l
    float cameraYaw;                            //�J�������[
    float cameraPitch;                          //�J�����s�b�`
    MATRIX cameraViewMat;                       //�r���[�s��
};

