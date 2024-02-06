#pragma once
#include<memory>

/// <summary>
/// マウスポインター
/// </summary>
class MousePoint
{
public:
    /// <summary>
    /// マウスポインター初期化処理
    /// </summary>
    static void InitMousePoint();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~MousePoint();

    /// <summary>
    /// 可視化
    /// </summary>
    static void CanVisible() { singleton->isVisible = true; }

    /// <summary>
    /// 不可視化
    /// </summary>
    static void UnVisible() { singleton->isVisible = false; }

    /// <summary>
    /// 描画
    /// </summary>
    static void Draw();

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    MousePoint();

    static std::unique_ptr<MousePoint> singleton;       //自身の実体
    bool isVisible;
    int mouseHandle;
};

