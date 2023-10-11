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
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">:フレームレート</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;
};

