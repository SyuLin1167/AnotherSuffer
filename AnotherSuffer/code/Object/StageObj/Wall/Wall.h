#pragma once
#include"../../StageObj/StageObjBase/StageObjBase.h"

/// <summary>
/// �ǃu���b�N
/// </summary>
class Wall final:public StageObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="pos">:���W</param>
    Wall(const VECTOR pos);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Wall();
};

