#pragma once

/*FPSクラス*/
class FPS
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    FPS();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~FPS();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// フレームレート取得処理
    /// </summary>
    /// <returns>フレームレート</returns>
    float GetDeltaTime() const { return deltaTime; }

private:
    float nowTime;      //現在の時間
    float prevTime;     //過去の時間
    float deltaTime;    //フレームレート
};

