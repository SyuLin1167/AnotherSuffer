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
    /// 視野外切り抜き処理
    /// </summary>
    void ViewClipBox();

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    std::shared_ptr<ObjBase> player;        //プレイヤー

    VECTOR clipBoxScale;                    //切り抜きボックススケール
    VECTOR clipBoxPos1;                     //切り抜きボックス座標1
    VECTOR clipBoxPos2;                     //切り抜きボックス座標2

    int texHandle;
    int texIndex;
};

