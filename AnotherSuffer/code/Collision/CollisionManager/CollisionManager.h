#pragma once
#include<unordered_map>

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

    /// <summary>
    /// �����蔻��ǉ�
    /// </summary>
    /// <param name="col">:�����蔻��</param>
    static void AddCol(CollisionBase* col);

    /// <summary>
    /// �����蔻��擾
    /// </summary>
    /// <param name="obj">:�I�u�W�F�N�g</param>
    /// <returns>�I�u�W�F�N�g�̓����蔻��</returns>
    static CollisionBase* GetCol(ObjBase* obj);

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

    static std::unique_ptr<CollisionManager> singleton;     //���g�̎���
    rapidjson::Document doc;                                //�h�L�������g
    std::unordered_map<ObjBase*, CollisionBase*> colData;   //�����蔻��f�[�^
};

