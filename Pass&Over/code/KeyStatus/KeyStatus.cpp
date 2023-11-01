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
    //�L�[���i�[����Ă��Ȃ�������ۑ�
    auto findKey = std::find(keyData.begin(), keyData.end(), key);
    if (findKey != keyData.end())
    {
        KeyParam keyParam = {};

        keyData.emplace(key, keyParam);
    }

    //���͂���Ă�����͎��̔��������
    auto& data = keyData[key];
    if (CheckHitKey(key))
    {
        //�����͏�ԂȂ�J�E���g������
        if (data.inputState = UNINPUT | NOWUNINPUT)
        {
            data.inputCount = 0.0f;
        }

        //�J�E���g�����Z���ďu�ԂƍŒ��̔�����Ƃ�
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
        //���͏�ԂȂ�J�E���g������
        if (data.inputState = ONINPUT | NOWINPUT)
        {
            data.inputCount = 0.0f;
        }

        //�J�E���g�����Z���ďu�ԂƍŒ��̔�����Ƃ�
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
    //�f�[�^�̒��g������Ȃ�폜
    if (keyData.size() > 0)
    {
        keyData.clear();
    }
}