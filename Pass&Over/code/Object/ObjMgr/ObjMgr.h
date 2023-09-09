#pragma once
#include<memory>

/*ObjMgrクラス*/
class ObjMgr final
{
public:
    /// <summary>
    /// オブジェクトマネージャー初期化処理
    /// </summary>
    void InitObjMgr();

    /// <summary>
    /// オブジェクト追加処理
    /// </summary>
    void AddObj();

    /// <summary>
    /// オブジェクト更新処理
    /// </summary>
    /// <param name="deltaTime">:フレームレート</param>
    void UpdateObj(const float& deltaTime);

    /// <summary>
    /// オブジェクト描画
    /// </summary>
    void DrawObj();

    /// <summary>
    /// 全オブジェクト削除処理
    /// </summary>
    void DeleteAllObj();
private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    ObjMgr();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ObjMgr();

    std::shared_ptr<ObjMgr> objMgr;     //自身の実体
};

