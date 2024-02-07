#pragma once
#include<memory>

static constexpr int MAX_PARAM = 500;           //パラメータ最大値

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
    /// 体力変動
    /// </summary>
    /// <param name="physic">:体力</param>
    static void ChangePhysicalParam(float physic);

    /// <summary>
    /// 描画
    /// </summary>
    static void Draw();

    /// <summary>
    /// 可視化状態取得
    /// </summary>
    /// <returns>可視:true|不可視:false</returns>
    static bool IsVisible() { return singleton->isVisible; }

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    PhysicalMeter();

    static std::unique_ptr<PhysicalMeter> singleton;        //自身の実体

    VERTEX2D vert[2][4];
    WORD idx[6] = { 0,1,2,3,2,1 };

    bool isVisible;
};

