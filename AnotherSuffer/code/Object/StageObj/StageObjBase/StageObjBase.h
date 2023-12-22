#pragma once

/// <summary>
/// ステージオブジェクトの基底クラス
/// </summary>
class StageObjBase:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    StageObjBase();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~StageObjBase();

private:
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// 視野外切り抜き
    /// </summary>
    void ViewClipBox();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

protected:
    VECTOR clipBoxScale;                    //切り抜きボックススケール
    VECTOR clipBoxPos1;                     //切り抜きボックス座標1
    VECTOR clipBoxPos2;                     //切り抜きボックス座標2
};

