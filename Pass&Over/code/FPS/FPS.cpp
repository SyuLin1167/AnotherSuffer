#include<DxLib.h>

#include "../FPS/FPS.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
FPS::FPS()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
    //�����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
FPS::~FPS()
{
    //�����Ȃ�
}

/// <summary>
/// �X�V����
/// </summary>
void FPS::Update()
{
    //�t���[�����[�g�Z�o
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;
}