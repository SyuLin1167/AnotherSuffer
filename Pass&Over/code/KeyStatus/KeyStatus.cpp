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

bool KeyStatus::KeyStateDecision(int key,const float deltaTime, int flag)
{
    //キーが格納されていなかったら保存
    auto findData = singleton->keyData.find(key);
    if (findData == singleton->keyData.end())
    {
        KeyParam keyParam = {};

        singleton->keyData.emplace(key, keyParam);
    }

    //ステータス切り替え
    ChangeKeyState(key, deltaTime);

    //判定結果を返す
    if (singleton->keyData[key].inputState == flag)
    {
        return true;
    }
    return false;
}

void KeyStatus::ChangeKeyState(int key, const float deltaTime)
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
            InitKeyData(data, UNINPUT | NOWUNINPUT, NOWINPUT);

            //カウントを加算して瞬間と最中の判定をとる
            if (data.inputCount < singleton->MAX_COUNT)
            {
                data.inputCount += deltaTime;
                if (data.inputCount < singleton->MOMENT_COUNT)
                {
                    data.inputState = ONINPUT;
                }
            }
        }
        else
        {
            //初期化処理
            InitKeyData(data, ONINPUT | NOWINPUT, NOWUNINPUT);

            //カウントを減算して瞬間と最中の判定をとる
            if (data.inputCount > singleton->MIN_COUNT)
            {
                data.inputCount -= deltaTime;
                data.deleteCount += deltaTime;
                if (data.inputCount > -singleton->MOMENT_COUNT)
                {
                    data.inputState = UNINPUT;
                }
            }
        }
    }
}

void KeyStatus::InitKeyData(KeyParam& data, int initFlag, int initState)
{
    //フラグと同じステータスだったらカウント初期化
    if (data.inputState = initFlag)
    {
        data.inputCount = 0.0f;
        data.deleteCount = 0.0f;
    }
    data.inputState = initState;
}

KeyStatus::KeyParam::KeyParam()
    :inputState(UNINPUT)
    , inputCount(0.0f)
    , deleteCount(0.0f)
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