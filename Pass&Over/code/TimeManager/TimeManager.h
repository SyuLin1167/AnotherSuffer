#pragma once

/*TimeManagerクラス*/
class TimeManager
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    TimeManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TimeManager();

    /// <summary>
    /// フレームレート
    /// </summary>
    /// <returns>フレームレート</returns>
    const float DeltaTime();

private:
    float nowTime;      //現在の時間
    float prevTime;     //過去の時間
    float deltaTime;    //フレームレート
};

