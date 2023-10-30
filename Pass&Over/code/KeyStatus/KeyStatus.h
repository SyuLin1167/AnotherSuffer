#pragma once
#include<DxLib.h>
#include<memory>

/// <summary>
/// KeyStatusクラス
/// </summary>
class KeyStatus
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
    /// <returns>入力:true|未入力:false</returns>
    bool IsInput(int key);

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
    /// 入力状態種類
    /// </summary>
    enum class KeyState
    {
        NOMAL=0,
        ONINPUT,
        NOWINPUT,
        UNINPUT,
    };

    static std::unique_ptr<KeyStatus> singleton;        //自身の実体

    int inputState;                                     //入力ステータス
};

