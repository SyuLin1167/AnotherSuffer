#include<DxLib.h>

#include "TimeManager.h"

// コンストラクタ //

TimeManager::TimeManager()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
}

// デストラクタ //

TimeManager::~TimeManager()
{
}

// フレームレート //

const float TimeManager::DeltaTime()
{
    //フレームレート算出
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;

    return deltaTime;
}