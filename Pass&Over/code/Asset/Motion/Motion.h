#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// モデルのモーション管理
/// </summary>
class Motion:public AssetBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Motion();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Motion();

    /// <summary>
    /// モーション再生処理
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    void StartMotion(int handle);

    /// <summary>
    /// モーション停止処理
    /// </summary>
    /// <param name="handle">:ハンドル</param>
    void StopMotion(int handle);

private:
    /// <summary>
    /// ハンドル追加処理
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(std::string fileName) override;

    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() override;
};

