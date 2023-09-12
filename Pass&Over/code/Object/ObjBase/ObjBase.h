#pragma once

/*ObjBase�N���X*/
class ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O</param>
    ObjBase(ObjTag tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~ObjBase();

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    virtual void Update(const float& deltaTime) = 0;

    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw() = 0;

    /// <summary>
    /// �^�O�擾
    /// </summary>
    /// <returns>�I�u�W�F�N�g�^�O</returns>
    ObjTag& GetTag();

    /// <summary>
    /// ��������
    /// </summary>
    /// <returns>��:true|��:false</returns>
    bool IsAlive() { return isAlive; }
protected:

    ObjTag objTag;
    bool isAlive;
};
