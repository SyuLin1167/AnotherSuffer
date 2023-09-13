#pragma once

/*CharaObjBase�N���X*/
class CharaObjBase:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CharaObjBase(ObjTag tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~CharaObjBase();

protected:
    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">�t���[�����[�g</param>
    virtual void Update(const float& deltaTime)override = 0;

    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw()override = 0;
};

