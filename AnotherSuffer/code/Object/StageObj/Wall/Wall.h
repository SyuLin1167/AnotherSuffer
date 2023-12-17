#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// 壁ブロック
/// </summary>
class Wall final:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Wall(VECTOR pos);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Wall();

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

    const float CLIP_BOX_SIZE = 150.0f;
    int texHandle;
};

