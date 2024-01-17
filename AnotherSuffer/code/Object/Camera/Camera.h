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

    std::shared_ptr<ObjBase> player;            //プレイヤー
    int handle;

    float rotRad;                               //回転角
    float rotAngle;                             //回転方向

    //// 三角関数を使用し、円の位置を割り出す。
    //float add_x = cos(radius) * enemy.m_Length;
    //float add_y = sin(radius) * enemy.m_Length;

    //// 結果ででた位置を中心位置に加算し、それを描画位置とする
    //enemy.m_PosX = enemy.m_CenterX + add_x;
    //enemy.m_PosY = enemy.m_CenterY + add_y;
};

