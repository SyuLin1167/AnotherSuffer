#pragma once
#include<DxLib.h>
#include<../Rapidjson/rapidjson.h>
#include<string.h>
#include<string>

#include"ObjTag.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../Asset/Model/Model.h"
#include"../../Asset/Sound/Sound.h"

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
    std::string GetTag() const { return objTag; }

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
    std::string objTag;     //�I�u�W�F�N�g�̃^�O

    bool isAlive;           //�������
    bool isVisible;         //������

    Model* model;           //���f��
    Sound* sound;           //�T�E���h

    int objHandle;          //�n���h��
    VECTOR objScale;        //�I�u�W�F�N�g�̑傫��
    VECTOR objPos;          //���W
    VECTOR objDir;          //����

};

