#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// 敵キャラ
/// </summary>
class Enemy final :public CharaObjBase
{
public:
    Enemy();
    ~Enemy();

private:
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="deltaTime">デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// キャラ動作
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void MoveChara(const float deltaTime) override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;
};