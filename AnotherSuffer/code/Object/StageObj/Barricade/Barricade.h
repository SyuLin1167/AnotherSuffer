#pragma once
#include"../StageObjBase/StageObjBase.h"

/// <summary>
/// ���
/// </summary>
class Barricade final:public StageObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="pos">:���W</param>
    Barricade(const VECTOR pos);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Barricade();
};

