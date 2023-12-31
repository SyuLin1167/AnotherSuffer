#pragma once
#include<../Rapidjson/istreamwrapper.h>
#include<../Rapidjson/document.h>
#include<fstream>
#include<string.h>
#include<string>
#include<memory>
#include<unordered_map>

#include"JsonKey.h"

/// <summary>
/// アセット基底クラス
/// </summary>
class AssetBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    AssetBase();

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~AssetBase();

    /// <summary>
    /// Jsonファイルデータ取得
    /// </summary>
    /// <returns>jsonファイルデータ</returns>
    rapidjson::Value& GetJsonData() { return doc[assetType.c_str()]; }

    /// <summary>
    /// ハンドル取得
    /// </summary>
    /// <param name="handleName">:ハンドル名</param>
    /// <returns>ハンドル</returns>
    int GetHandle(const std::string handleName) const;

protected:
    /// <summary>
    /// Jsonファイル読み込み
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void LoadJsonFile(const std::string fileName);

    /// <summary>
    /// ハンドル追加
    /// </summary>
    virtual void AddHandle(const std::string fileName) = 0;

    /// <summary>
    /// ハンドル削除
    /// </summary>
    virtual void DeleteHandle() = 0;

    int holdHandle;                  //一時保存ハンドル
    int dupHandle;                   //複製ハンドル

    std::string assetType;                              //アセットタイプ
    std::unordered_map < std::string, int > handle;     //ハンドル

    std::string jsonFile;                               //jsonファイル
    rapidjson::Document doc;                            //ドキュメント
};

