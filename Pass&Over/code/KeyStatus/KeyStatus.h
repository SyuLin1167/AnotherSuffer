#pragma once
#include<unordered_map>
#include<memory>

constexpr int UNINPUT = 0x0001;     //未入力時
constexpr int NOWUNINPUT = 0x0002;  //未入力中
constexpr int ONINPUT = 0x0004;     //入力時
constexpr int NOWINPUT = 0x0008;    //入力中

/// <summary>
/// KeyStatusクラス
/// </summary>
class KeyStatus final
{
public:
    /// <summary>
    /// キー入力初期化処理
    /// </summary>
    void CreateInstance();

    /// <summary>
    /// 入力判定処理
    /// </summary>
    /// <param name="key">:判定したいキー</param>
    /// <param name="deltaTime">:デルタタイム</param>
    void KeyStateDecision(int key, float deltaTime);


    /// <summary>
    /// デストラクタ
    /// </summary>
    ~KeyStatus();
private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    KeyStatus();


    static std::unique_ptr<KeyStatus> singleton;        //自身の実体

    const float MAX_COUNT = 1.0f;                       //最大カウント値
    const float MIN_COUNT = -1.0f;                      //最小カウント値
    const float MOMENT_COUNT = 0.001f;                  //瞬間カウント値
    const float DELETE_COUNT = 600.0f;                  //データ削除用カウント

    /// <summary>
    /// キーパラメーター
    /// </summary>
    struct KeyParam
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        KeyParam();

        int inputState;             //入力ステータス
        float inputCount;           //入力カウント
    };

    std::unordered_map<int ,KeyParam> keyData;          //キーデータ
};

