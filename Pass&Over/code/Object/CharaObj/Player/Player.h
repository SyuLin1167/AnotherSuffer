#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// Playerクラス
/// </summary>
class Player final:public CharaObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Player();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Player();

private:
    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;

    float a = 0;
};

