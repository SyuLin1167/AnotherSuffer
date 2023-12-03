#pragma once
#include<DxLib.h>
#include<memory>

/// <summary>
/// ゲームプロセス管理
/// </summary>
class GameManager
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameManager();

    /// <summary>
    /// 実行処理
    /// </summary>
    void Procces();
};

