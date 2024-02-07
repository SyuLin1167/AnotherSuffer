#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// �^�C�g����ʗp�̓G
/// </summary>
class TitleEnemy final:public CharaObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    TitleEnemy();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~TitleEnemy();

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
    /// �����蔻��
    /// </summary>
    /// <param name="colObj">:���肷��I�u�W�F�N�g</param>
    void OnCollisionEnter(class ObjBase* colObj) override;

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    class Capsule* capsule;         //�J�v�Z���^����
};

