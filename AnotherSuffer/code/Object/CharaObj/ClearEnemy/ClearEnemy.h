#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// クリア時の敵
/// </summary>
class ClearEnemy:public CharaObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    ClearEnemy();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ClearEnemy();

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

    int clearGraph;
};

