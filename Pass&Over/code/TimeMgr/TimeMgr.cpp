#include<DxLib.h>

#include "TimeMgr.h"

// �R���X�g���N�^ //

TimeMgr::TimeMgr()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
}

// �f�X�g���N�^ //

TimeMgr::~TimeMgr()
{
}

// �t���[�����[�g //

const float TimeMgr::DeltaTime()
{
    //�t���[�����[�g�Z�o
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;

    return deltaTime;
}