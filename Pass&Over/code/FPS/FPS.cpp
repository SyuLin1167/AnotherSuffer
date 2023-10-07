#include<DxLib.h>

#include "../FPS/FPS.h"

// �R���X�g���N�^ //

FPS::FPS()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
}

// �f�X�g���N�^ //

FPS::~FPS()
{
    //�����Ȃ�
}

// �X�V���� //

void FPS::Update()
{
    //�t���[�����[�g�Z�o
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;
}