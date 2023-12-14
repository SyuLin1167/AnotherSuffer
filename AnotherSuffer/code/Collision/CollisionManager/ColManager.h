#pragma once
#include"../../Object/ObjBase/ObjBase.h"

/// <summary>
/// �����蔻��̊Ǘ�
/// </summary>
class ColManager
{
public:
    /// <summary>
    /// �R���W�����}�l�[�W���[������
    /// </summary>
    static void InitColManager();

    /// <summary>
    /// �����蔻��g�ݍ��킹����
    /// </summary>
    static void CheckCollisionPair();

    /// <summary>
    /// �����蔻��
    /// </summary>
    static void OnCollisionEnter();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~ColManager();
private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    ColManager();

    static std::unique_ptr<ColManager> singleton;   //���g�̎���
    rapidjson::Document doc;                            //�h�L�������g
};

