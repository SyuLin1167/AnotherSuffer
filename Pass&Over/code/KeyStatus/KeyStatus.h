#pragma once
#include<vector>
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

    const float MAXCOUNT = 1.0f;
    const float MINCOUNT = -1.0f;

    /// <summary>
    /// キーパラメーター
    /// </summary>
    struct KeyParam
    {
    public:
        KeyParam();

        int inputState;             //入力ステータス
        float inputCount;           //入力カウント
    };

    std::vector<KeyParam> keyData;  //キーデータ
};

