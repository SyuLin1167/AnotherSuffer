#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// CharaObjBase�N���X
/// </summary>
class CharaObjBase:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O��</param>
    CharaObjBase(std::string tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~CharaObjBase();

protected:
    /// <summary>
    /// �L�������쏈��
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    //virtual void MoveChara(const float deltaTime);

    /// <summary>
    /// �L������]����
    /// </summary>
    //void RotateModel();
};

