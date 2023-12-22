#include<DxLib.h>

#include "../FPS/FPS.h"

std::unique_ptr<FPS> FPS::singleton = nullptr;

FPS::FPS()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime()
{
    //処理なし
}

void FPS::InitFPS()
{
    //インスタンス初期化
    if (!singleton)
    {
        singleton.reset(new FPS);
    }
}

FPS::~FPS()
{
    //処理なし
}

void FPS::Update()
{
    //フレームレート算出
    singleton->nowTime = static_cast<float>(GetNowCount());
    singleton->deltaTime = (singleton->nowTime - singleton->prevTime) / 1000.0f;
    singleton->prevTime = singleton->nowTime;
}