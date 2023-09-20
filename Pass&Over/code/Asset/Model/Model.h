#pragma once
#include<string>
#include<unordered_map>

/*Modelクラス*/
class Model final
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
    void DeleteHandle();

private:
    std::unordered_map<std::string, int> modelData;
    std::vector<int> modelHandle;
};

