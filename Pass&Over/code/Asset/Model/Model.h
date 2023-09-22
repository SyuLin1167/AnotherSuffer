#pragma once
#include"../AssetBase/AssetBase.h"

/*Modelクラス*/
class Model final:public AssetBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Model();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Model();

    /// <summary>
    /// ハンドル追加処理
    /// </summary>
    void AddHandle();

    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() override;

private:
};

