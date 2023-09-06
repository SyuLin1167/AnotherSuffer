#include<DxLib.h>

#include "TimeMgr.h"

// コンストラクタ //

TimeMgr::TimeMgr()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
}

// デストラクタ //

TimeMgr::~TimeMgr()
{
}

// フレームレート //

const float TimeMgr::DeltaTime()
{
    //フレームレート算出
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;

    return deltaTime;
}