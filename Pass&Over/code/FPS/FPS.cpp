#include<DxLib.h>

#include "../FPS/FPS.h"

FPS::FPS()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
    //処理なし
}

FPS::~FPS()
{
    //処理なし
}

void FPS::Update()
{
    //フレームレート算出
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;
}