#pragma once

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
    /// ハンドル取得処理
    /// </summary>
    /// <param name="modelName">モデル名</param>
    /// <returns>ハンドル</returns>
    int GetHandle(std::string modelName);

    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    void DeleteHandle();

private:
    std::unordered_map<std::string, int> modelData;
    std::vector<int> modelHandle;
};

