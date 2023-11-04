#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// モデル管理
/// </summary>
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
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() override;

private:
    /// <summary>
    /// ハンドル追加処理
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(const std::string fileName) override;
};

