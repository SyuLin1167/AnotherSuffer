#include<DxLib.h>

#include "../FPS/FPS.h"

/// <summary>
/// コンストラクタ
/// </summary>
FPS::FPS()
    :nowTime(static_cast<float>(GetNowCount()))
    ,prevTime(nowTime)
    ,deltaTime(0.0f)
{
    //処理なし
}

/// <summary>
/// デストラクタ
/// </summary>
FPS::~FPS()
{
    //処理なし
}

/// <summary>
/// 更新処理
/// </summary>
void FPS::Update()
{
    //フレームレート算出
    nowTime = static_cast<float>(GetNowCount());
    deltaTime = (nowTime - prevTime) / 1000.0f;
    prevTime = nowTime;
}