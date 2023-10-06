#include<DxLib.h>

#include "TimeManager.h"

// �R���X�g���N�^ //

TimeManager::TimeManager()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
}

// �f�X�g���N�^ //

TimeManager::~TimeManager()
{
}

// �t���[�����[�g //

const float TimeManager::DeltaTime()
{
    //�t���[�����[�g�Z�o
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;

    return deltaTime;
}