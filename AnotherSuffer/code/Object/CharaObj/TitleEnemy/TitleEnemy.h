#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// タイトル画面用の敵
/// </summary>
class TitleEnemy final:public CharaObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    TitleEnemy();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TitleEnemy();

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
    /// 当たり判定
    /// </summary>
    /// <param name="colObj">:判定するオブジェクト</param>
    void OnCollisionEnter(class ObjBase* colObj) override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    class Capsule* capsule;         //カプセル型判定
};

