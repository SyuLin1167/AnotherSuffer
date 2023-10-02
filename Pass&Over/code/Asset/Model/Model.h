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
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(std::string fileName)override;

    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() override;

private:
    int tmpHandle;                  //一時保存ハンドル
    int dupHandle;                  //複製ハンドル
};

