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
    auto findKey = std::find(keyData.begin(), keyData.end(), key);

    if (findKey != keyData.end())
    {
        if (CheckHitKey(key))
        {

        }
    }
}