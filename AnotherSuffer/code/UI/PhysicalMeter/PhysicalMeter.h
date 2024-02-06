#pragma once
#include<memory>

/// <summary>
/// 体力バー
/// </summary>
class PhysicalMeter
{
public:
    /// <summary>
    /// 体力バー初期化
    /// </summary>
    static void InitPhysicalMeter();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PhysicalMeter();

    /// <summary>
    /// 描画
    /// </summary>
    static void Draw();

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    PhysicalMeter();

    static std::unique_ptr<PhysicalMeter> singleton;        //自身の実体

    VERTEX2D vert[2][4];
    WORD idx[6] = { 0,1,2,3,2,1 };
};

