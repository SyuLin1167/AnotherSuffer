#include<DxLib.h>
#include "KeyStatus.h"

std::unique_ptr<KeyStatus> KeyStatus::singleton = nullptr;

void KeyStatus::CreateInstance()
{
    //自身の中身が空だったらインスタンス生成
    if (!singleton)
    {
        singleton.reset(new KeyStatus);
    }
}


KeyStatus::KeyStatus()
{
    //処理なし
}

void KeyStatus::KeyStateDecision(int key, float deltaTime)
{
    //キーが格納されていなかったら保存
    auto findKey = std::find(keyData.begin(), keyData.end(), key);
    if (findKey != keyData.end())
    {
        KeyParam keyParam = {};

        keyData.emplace(key, keyParam);
    }

    //入力されてたら入力時の判定をする
    auto& data = keyData[key];
    if (CheckHitKey(key))
    {
        //未入力状態ならカウント初期化
        if (data.inputState = UNINPUT | NOWUNINPUT)
        {
            data.inputCount = 0.0f;
        }

        //カウントを加算して瞬間と最中の判定をとる
        if (data.inputCount < MAX_COUNT)
        {
            data.inputCount += deltaTime;
            data.inputState = NOWINPUT;

            if (data.inputCount < MOMENT_COUNT)
            {
                    data.inputState = ONINPUT;
            }
        }
    }
    else
    {
        //入力状態ならカウント初期化
        if (data.inputState = ONINPUT | NOWINPUT)
        {
            data.inputCount = 0.0f;
        }

        //カウントを減算して瞬間と最中の判定をとる
        if (data.inputCount > MIN_COUNT)
        {
            data.inputCount -= deltaTime;
            data.inputState = NOWUNINPUT;

            if (data.inputCount > -MOMENT_COUNT)
            {
                data.inputState = UNINPUT;
            }
        }
    }
}

KeyStatus::KeyParam::KeyParam()
    :inputState(UNINPUT)
    , inputCount(0.0f)
{
}

KeyStatus::~KeyStatus()
{
    //データの中身があるなら削除
    if (keyData.size() > 0)
    {
        keyData.clear();
    }
}