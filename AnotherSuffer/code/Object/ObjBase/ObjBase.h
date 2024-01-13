#pragma once
#include<DxLib.h>
#include<../Rapidjson/rapidjson.h>
#include<../Rapidjson/document.h>
#include<string.h>
#include<string>

#include"ObjTag.h"

/// <summary>
/// �I�u�W�F�N�g���N���X
/// </summary>
class ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O</param>
    ObjBase(std::string tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~ObjBase();

    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    virtual void Update(const float deltaTime) = 0;

    /// <summary>
    /// �����蔻��
    /// </summary>
    /// <param name="colObj">:���肷��I�u�W�F�N�g</param>
    virtual void OnCollisionEnter(ObjBase* colObj) {};

    /// <summary>
    /// �`��
    /// </summary>
    virtual void Draw() = 0;

    /// <summary>
    /// �^�O�擾
    /// </summary>
    /// <returns>�I�u�W�F�N�g�^�O</returns>
    std::string GetTag() const { return objTag; }

    /// <summary>
    /// �n���h���擾
    /// </summary>
    /// <returns></returns>
    int GetObjHandle() const { return objHandle; }

    /// <summary>
    /// ���W�擾
    /// </summary>
    /// <returns>���W</returns>
    VECTOR GetObjPos() const { return objPos; }

    /// <summary>
    /// �t���[�����W�擾
    /// </summary>
    /// <returns>�w��̃t���[�����W</returns>
    VECTOR GetObjFramePos(int frameIdx) const { return MV1GetFramePosition(objHandle, frameIdx); }

    /// <summary>
    /// �����擾
    /// </summary>
    /// <returns>����</returns>
    VECTOR GetObjDir() const { return objDir; }

    /// <summary>
    /// �����蔻����擾
    /// </summary>
    /// <returns>:�����蔻����</returns>
    MV1_COLL_RESULT_POLY_DIM GetColInfo()const { return colInfo; }

    /// <summary>
    /// ��������
    /// </summary>
    /// <returns>��:true|��:false</returns>
    bool IsAlive() const { return isAlive; }

    /// <summary>
    /// ������
    /// </summary>
    /// <returns>��:true|�s��:false</returns>
    bool IsVisible() const { return isVisible; }

protected:
    /// <summary>
    /// �I�u�W�F�N�g���W�Z�o
    /// </summary>
    /// <returns>���W</returns>
    void CalcObjPos();

    std::string objTag;     //�I�u�W�F�N�g�̃^�O

    bool isAlive;           //�������
    bool isVisible;         //������

    int objHandle;          //�n���h��
    //int frameIdx;           //�t���[���̃C���f�b�N�X�ԍ�

    VECTOR objScale;        //�I�u�W�F�N�g�̑傫��
    VECTOR objPos;          //���W
    VECTOR objWorldPos;     //���[���h���W
    VECTOR objLocalPos;     //���[�J�����W
    VECTOR objDir;          //����

    MV1_COLL_RESULT_POLY_DIM colInfo;
};

