#include<DxLib.h>
#include "KeyStatus.h"

std::unique_ptr<KeyStatus> KeyStatus::singleton = nullptr;

void KeyStatus::CreateInstance()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        singleton.reset(new KeyStatus);
    }
}


KeyStatus::KeyStatus()
{
    //�����Ȃ�
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