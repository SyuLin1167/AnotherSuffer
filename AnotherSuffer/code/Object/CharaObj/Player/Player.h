#pragma once
#include"../CharaObjBase/CharaObjBase.h"

static constexpr float MAX_PHYSICAL = 50;

/// <summary>
/// �v���C���[
/// </summary>
class Player final:public CharaObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Player();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Player();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �L��������
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void MoveChara(const float deltaTime) override;

    /// <summary>
    /// �L�[���͂ɂ��ړ�
    /// </summary>
    /// <param name="keyName">:�L�[��</param>
    /// <param name="dir">:�ړ�����</param>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void MoveByKey(const int keyName, const VECTOR dir, const float deltaTime);

    /// <summary>
    /// �����蔻��
    /// </summary>
    /// <param name="colObj">:���肷��I�u�W�F�N�g</param>
    void OnCollisionEnter(class ObjBase* colObj) override;

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    float physical;
    bool canRunning;

    float a = 0;
    int texHandle;
    int test;
    ObjBase* camera;
    class Capsule* capsule;
    VECTOR moveVel;
};

