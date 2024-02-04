#pragma once
#include"../../CharaObj/CharaObjBase/CharaObjBase.h"

class FixedCamera final:public CharaObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="pos">:���W</param>
    /// <param name="dir">:����</param>
    FixedCamera(const VECTOR& pos, const VECTOR& dir);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~FixedCamera();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �L��������
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void MoveChara(const float deltaTime) override {};

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    ObjBase* enemy;            //�G�l�~�[
    int lightHandle;            //���C�g�n���h��
};

