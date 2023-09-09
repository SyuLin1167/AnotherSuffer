#pragma once
#include<memory>

/*ObjMgr�N���X*/
class ObjMgr final
{
public:
    /// <summary>
    /// �I�u�W�F�N�g�}�l�[�W���[����������
    /// </summary>
    void InitObjMgr();

    /// <summary>
    /// �I�u�W�F�N�g�ǉ�����
    /// </summary>
    void AddObj();

    /// <summary>
    /// �I�u�W�F�N�g�X�V����
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    void UpdateObj(const float& deltaTime);

    /// <summary>
    /// �I�u�W�F�N�g�`��
    /// </summary>
    void DrawObj();

    /// <summary>
    /// �S�I�u�W�F�N�g�폜����
    /// </summary>
    void DeleteAllObj();
private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    ObjMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~ObjMgr();

    std::shared_ptr<ObjMgr> objMgr;     //���g�̎���
};

