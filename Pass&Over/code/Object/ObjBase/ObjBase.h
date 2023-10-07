#pragma once
#include<DxLib.h>
#include<../Rapidjson/istreamwrapper.h>
#include<string.h>
#include<string>

#include"ObjTag.h"
#include"../../Asset/AssetMgr/AssetMgr.h"

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
    virtual ~ObjBase();

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    virtual void Update(const float deltaTime) = 0;

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
    ObjTag objTag;      //�I�u�W�F�N�g�̃^�O

    bool isAlive;       //�������

    int objHandle;      //�n���h��
    VECTOR objPos;    //���W
};

