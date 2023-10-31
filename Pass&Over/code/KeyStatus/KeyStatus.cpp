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
    :inputState(0)
{
}

bool IsInput(int key)
{
    //入力してたらtrueしていなかったらfalseを返す
    if (key != 0)
    {
        return true;
    }

    return false;
}