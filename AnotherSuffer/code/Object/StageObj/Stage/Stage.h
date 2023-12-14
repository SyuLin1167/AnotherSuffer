#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// ステージのブロック
/// </summary>
class Stage final:public ObjBase
{
public:
    Stage() :ObjBase(ObjTag.STAGE) {};

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Stage(VECTOR pos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Stage();

private:
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="deltaTime">デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    const float CLIP_BOX_SIZE = 200.0f;
};

