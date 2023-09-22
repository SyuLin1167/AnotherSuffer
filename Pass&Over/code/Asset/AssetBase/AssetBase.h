#pragma once
#include<memory>
#include<string>
#include<unordered_map>
#include<../../IncludeFile/Rapidjson/istreamwrapper.h>
#include<../../IncludeFile/Rapidjson/document.h>

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
    /// ハンドル追加処理
    /// </summary>
    virtual void AddHandle() = 0;

    /// <summary>
    /// ハンドル取得処理
    /// </summary>
    /// <param name="handleName">ハンドル名</param>
    /// <returns>ハンドル</returns>
    int GetHandle(std::string handleName);

    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() = 0;

protected:
    std::unordered_map < std::string, std::unique_ptr<int> > handle;     //ハンドル
};

