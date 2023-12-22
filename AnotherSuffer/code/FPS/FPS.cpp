#include<DxLib.h>

#include "../FPS/FPS.h"

std::unique_ptr<FPS> FPS::singleton = nullptr;

FPS::FPS()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime()
{
    //�����Ȃ�
}

void FPS::InitFPS()
{
    //�C���X�^���X������
    if (!singleton)
    {
        singleton.reset(new FPS);
    }
}

FPS::~FPS()
{
    //�����Ȃ�
}

void FPS::Update()
{
    //�t���[�����[�g�Z�o
    singleton->nowTime = static_cast<float>(GetNowCount());
    singleton->deltaTime = (singleton->nowTime - singleton->prevTime) / 1000.0f;
    singleton->prevTime = singleton->nowTime;
}