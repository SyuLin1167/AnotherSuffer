#pragma once
#include"../../StageObj/StageObjBase/StageObjBase.h"

/// <summary>
/// �n�ʃu���b�N
/// </summary>
class Aisle final:public StageObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
     /// <param name="pos">:���W</param>
    Aisle(const VECTOR pos);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Aisle();
};

