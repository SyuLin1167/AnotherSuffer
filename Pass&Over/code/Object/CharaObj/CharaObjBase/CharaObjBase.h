#pragma once

/*CharaObjBaseクラス*/
class CharaObjBase:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CharaObjBase(ObjTag tag);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~CharaObjBase();

protected:
    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">フレームレート</param>
    virtual void Update(const float& deltaTime)override = 0;

    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw()override = 0;
};

