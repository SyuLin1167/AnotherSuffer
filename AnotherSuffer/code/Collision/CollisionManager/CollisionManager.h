#pragma once
#include"../../Object/ObjBase/ObjBase.h"
#include"../CollisionBase/CollisionBase.h"

/// <summary>
/// �����蔻��̊Ǘ�
/// </summary>
class CollisionManager final
{
public:
    /// <summary>
    /// �R���W�����}�l�[�W���[������
    /// </summary>
    static void InitColManager();

    static void AddCol();
    static CollisionBase* GetCol();

    /// <summary>
    /// �����蔻��g�ݍ��킹����
    /// </summary>
    static void CheckCollisionPair();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CollisionManager();
private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    CollisionManager();

    /// <summary>
    /// �����蔻��
    /// </summary>
    /// <param name="mainObj">:��I�u�W�F�N�g�^�O</param>
    /// <param name="pairObj">:�y�A�I�u�W�F�N�g�^�O</param>
    static void OnCollisionEnter(std::string mainObjTag, std::string pairObjTag);

    static std::unique_ptr<CollisionManager> singleton;   //���g�̎���
    rapidjson::Document doc;                            //�h�L�������g
};

