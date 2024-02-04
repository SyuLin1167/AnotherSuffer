#pragma once
#include"../../CharaObj/CharaObjBase/CharaObjBase.h"

class FixedCamera final:public CharaObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="pos">:座標</param>
    /// <param name="dir">:方向</param>
    FixedCamera(const VECTOR& pos, const VECTOR& dir);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~FixedCamera();

private:
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// キャラ動作
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void MoveChara(const float deltaTime) override {};

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    ObjBase* enemy;            //エネミー
    int lightHandle;            //ライトハンドル
};

