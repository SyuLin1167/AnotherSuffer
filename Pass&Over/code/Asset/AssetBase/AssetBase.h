#pragma once
#include<memory>
#include<unordered_map>
#include<../Rapidjson/istreamwrapper.h>
#include<../Rapidjson/document.h>
#include<string.h>
#include<string>
#include<fstream>

/*AssetBaseクラス*/
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
    /// Jsonファイル読み込み処理
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void LoadJsonFile(std::string fileName);

    /// <summary>
    /// ハンドル追加処理
    /// </summary>
    virtual void AddHandle(std::string fileName) = 0;

    /// <summary>
    /// Jsonファイルデータ取得処理
    /// </summary>
    /// <returns>jsonファイルデータ</returns>
    const rapidjson::Value& GetJsonData() { return doc[assetType.c_str()]; }

    /// <summary>
    /// ハンドル取得処理
    /// </summary>
    /// <param name="handleName">:ハンドル名</param>
    /// <returns>ハンドル</returns>
    const int GetHandle(std::string handleName);

    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() = 0;

protected:
    std::string assetType;                              //アセットタイプ
    std::unordered_map < std::string, int > handle;     //ハンドル

    std::string jsonFile;                               //jsonファイル
    rapidjson::Document doc;                            //ドキュメント
};

