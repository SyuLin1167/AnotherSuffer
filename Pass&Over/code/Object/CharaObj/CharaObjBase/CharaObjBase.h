#pragma once
#include"../../ObjBase/ObjBase.h"

/*CharaObjBase�N���X*/
class CharaObjBase:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CharaObjBase(ObjTag tag);

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


};

