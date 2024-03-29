#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// TitleCameraクラス
/// </summary>
class TitleCamera final:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    TitleCamera();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TitleCamera();

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

    std::shared_ptr<ObjBase> player;            //プレイヤー
    int handle;

    float rotRad;                               //回転角
    float rotAngle;                             //回転方向
};

