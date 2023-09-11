#pragma once
#include<memory>
#include<vector>
#include<unordered_map>

/*ObjMgr�N���X*/
class ObjMgr final
{
public:
    /// <summary>
    /// �I�u�W�F�N�g�}�l�[�W���[����������
    /// </summary>
    static void InitObjMgr();

    /// <summary>
    /// �I�u�W�F�N�g�ǉ�����
    /// </summary>
    static void AddObj(ObjBase* newObj);

    /// <summary>
    /// �I�u�W�F�N�g�X�V����
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    static void UpdateObj(const float& deltaTime);

    /// <summary>
    /// �I�u�W�F�N�g���S����
    /// </summary>
    static void OnDeadObj();

    /// <summary>
    /// �I�u�W�F�N�g�`��
    /// </summary>
    static void DrawObj();

    /// <summary>
    /// �I�u�W�F�N�g�폜����
    /// </summary>
    /// <param name="unnecObj">:�s�K�v�I�u�W�F�N�g</param>
    static void DeleteObj(ObjBase* unnecObj);

    /// <summary>
    /// �S�I�u�W�F�N�g�폜����
    /// </summary>
    static void DeleteAllObj();
private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    ObjMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~ObjMgr();

    static std::shared_ptr<class ObjMgr> objMgr;     //���g�̎���

    std::unordered_map<ObjTag, std::vector<
        std::shared_ptr<class ObjBase>>> object;     //�I�u�W�F�N�g
};

