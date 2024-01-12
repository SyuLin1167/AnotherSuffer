#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// 画像管理
/// </summary>
class Graph final :public AssetBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Graph();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Graph();

private:
    /// <summary>
    /// ハンドル追加
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(const std::string fileName) override;

    /// <summary>
    /// ハンドル削除
    /// </summary>
    void DeleteHandle() override;
};

