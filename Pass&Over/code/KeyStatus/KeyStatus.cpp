#include<DxLib.h>
#include "KeyStatus.h"

std::unique_ptr<KeyStatus> KeyStatus::singleton = nullptr;

void KeyStatus::InitKeyStatus()
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

bool KeyStatus::KeyStateDecision(int key, int flag)
{
    //キーが格納されていなかったら保存
    auto findData = singleton->keyData.find(key);
    if (findData == singleton->keyData.end())
    {
        KeyParam keyParam = {};

        singleton->keyData.emplace(key, keyParam);
    }

    //ステータス切り替え
    ChangeKeyState(key);

    //判定結果を返す
    if (singleton->keyData[key].inputState & flag)
    {
        return true;
    }
    return false;
}

void KeyStatus::ChangeKeyState(int key)
{
    //キーが格納されてたら切り替え処理
    auto findData = singleton->keyData.find(key);
    if (findData != singleton->keyData.end())
    {
        auto& data = singleton->keyData[key];

        //ステータスの切り替えをする
        if (CheckHitKey(key))
        {
            //初期化処理
            if (data.inputState & (UNINPUT | NOWUNINPUT))
            {
                data.inputState = ONINPUT;
                return;
            }
            data.inputState = NOWONINPUT;
        }
        else
        {
            //初期化処理
            if (data.inputState & (ONINPUT | NOWONINPUT))
            {
                data.inputState = UNINPUT;
                return;
            }
            data.inputState = NOWUNINPUT;
        }
    }
}

KeyStatus::KeyParam::KeyParam()
    :inputState(UNINPUT)
{
    //処理なし
}

KeyStatus::~KeyStatus()
{
    //データの中身があるなら削除
    if (keyData.size() > 0)
    {
        keyData.clear();
    }
}