#pragma once
#include<memory>

/*AssetMgrクラス*/
class AssetMgr final
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    AssetMgr();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~AssetMgr();

    /// <summary>
    /// モデルインスタンス
    /// </summary>
    /// <returns>Modelクラス</returns>
    Model ModelInstance() { return *model; }

private:
    std::unique_ptr<class Model> model;     //モデル
};

