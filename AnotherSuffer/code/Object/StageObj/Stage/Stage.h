#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// ステージ
/// </summary>
class Stage final:public ObjBase
{
public:
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
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;
};

