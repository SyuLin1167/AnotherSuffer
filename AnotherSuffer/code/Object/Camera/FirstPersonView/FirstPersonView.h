#pragma once
#include"../../ObjBase/ObjBase.h"

constexpr float CAMERA_NEAR = 0.1f;
constexpr float CAMERA_FAR = 500.0f;

/// <summary>
/// 一人称視点
/// </summary>
class FirstPersonView final:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    FirstPersonView();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~FirstPersonView();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// 視点の移動量算出
    /// </summary>
    void CalcMoveView();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;

private:
    int mousePosX;      //マウス座標X
    int mousePosY;      //マウス座標Y
    VECTOR angleVel;    //移動量

    const VECTOR ANGLE_POS = VGet(0, 20, 0);   //視点座標

    float cameraYaw;    //カメラヨー
    float cameraPitch;  //カメラピッチ
    MATRIX cameraView;  //ビュー行列
};

