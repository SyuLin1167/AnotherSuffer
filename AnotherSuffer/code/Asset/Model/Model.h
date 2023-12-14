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
    /// ハンドル削除
    /// </summary>
    void DeleteHandle() override;

private:
    /// <summary>
    /// ハンドル追加
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(const std::string fileName) override;
};

