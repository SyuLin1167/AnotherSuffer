#include<DxLib.h>

#include "../FPS/FPS.h"

// コンストラクタ //

FPS::FPS()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
}

// デストラクタ //

FPS::~FPS()
{
    //処理なし
}

// 更新処理 //

void FPS::Update()
{
    //フレームレート算出
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;
}