#pragma once
#include<memory>

/// <summary>
/// KeyStatusクラス
/// </summary>
class KeyStatus
{
public:
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
        AFTERINPUT,
    };

    static std::unique_ptr<KeyStatus> singleton;        //自身の実体

    int inputState;
};

