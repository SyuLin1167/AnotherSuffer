#pragma once
#include<DxLib.h>
#include<../Rapidjson/istreamwrapper.h>
#include<string.h>
#include<string>

#include"ObjTag.h"
#include"../../Asset/AssetManager/AssetManager.h"

/// <summary>
/// ObjBase�N���X
/// </summary>
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
    /// <param name="deltaTime">:�f���^�^�C��</param>
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

    /// <summary>
    /// ������
    /// </summary>
    /// <returns>��:true|�s��:false</returns>
    bool IsVisible() { return isVisible; }

protected:
    ObjTag objTag;      //�I�u�W�F�N�g�̃^�O

    bool isAlive;       //�������
    bool isVisible;     //������

    int objHandle;      //�n���h��
    VECTOR objPos;      //���W
    VECTOR objDir;      //����
};

