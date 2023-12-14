#pragma once
#include"../ObjBase/ObjBase.h"

/// <summary>
/// Cameraクラス
/// </summary>
class Camera final:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Camera();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Camera();

private:
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;
};

