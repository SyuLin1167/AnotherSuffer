#pragma once

/*TimeMgrクラス*/
class TimeMgr
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    TimeMgr();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TimeMgr();

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

