#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/*Player�N���X*/
class Player:public CharaObjBase
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
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">�t���[�����[�g</param>
    void Update(const float& deltaTime)override;

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;

    float a = 0;
};

