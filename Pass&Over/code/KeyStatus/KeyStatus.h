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
    static void InitKeyStatus();

    /// <summary>
    /// 入力判定処理
    /// </summary>
    /// <param name="key">:判定したいキー</param>
    /// <param name="deltaTime">:デルタタイム</param>
    /// <param name="flag">:判定フラグ</param>
    /// <returns>キーステータスがフラグと一致:true|不一致:false</returns>
    static bool KeyStateDecision(int key,const float deltaTime,int flag);


    /// <summary>
    /// デストラクタ
    /// </summary>
    ~KeyStatus();
private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    KeyStatus();

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
        float deleteCount;          //削除カウント
    };

    /// <summary>
    /// キーステータス初期化処理
    /// </summary>
    /// <param name="data">:データ</param>
    /// <param name="initFlag">:初期化用フラグ</param>
    /// <param name="initState">:初期化用ステータス</param>
    static void InitKeyData(KeyParam& data, int initFlag, int initState);

    /// <summary>
    /// キーステータス切り替え処理
    /// </summary>
    /// <param name="key">:切り替えたいキー</param>
    /// <param name="deltaTime">:デルタタイム</param>
    static void ChangeKeyState(int key, const float deltaTime);

    static std::unique_ptr<KeyStatus> singleton;        //自身の実体

    const float MAX_COUNT = 1.0f;                       //最大カウント値
    const float MIN_COUNT = -1.0f;                      //最小カウント値
    const float MOMENT_COUNT = 0.01f;                   //瞬間カウント値


    std::unordered_map<int ,KeyParam> keyData;          //キーデータ
};

