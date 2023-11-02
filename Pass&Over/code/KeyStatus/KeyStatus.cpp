#include<DxLib.h>
#include "KeyStatus.h"

std::unique_ptr<KeyStatus> KeyStatus::singleton = nullptr;

void KeyStatus::InitKeyStatus()
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

bool KeyStatus::KeyStateDecision(int key,const float deltaTime, int flag)
{
    //�L�[���i�[����Ă��Ȃ�������ۑ�
    auto findData = singleton->keyData.find(key);
    if (findData == singleton->keyData.end())
    {
        KeyParam keyParam = {};

        singleton->keyData.emplace(key, keyParam);
    }

    //�X�e�[�^�X�؂�ւ�
    ChangeKeyState(key, deltaTime);

    //���茋�ʂ�Ԃ�
    if (singleton->keyData[key].inputState == flag)
    {
        return true;
    }
    return false;
}

void KeyStatus::ChangeKeyState(int key, const float deltaTime)
{
    //�L�[���i�[����Ă���؂�ւ�����
    auto findData = singleton->keyData.find(key);
    if (findData != singleton->keyData.end())
    {
        auto& data = singleton->keyData[key];

        //�X�e�[�^�X�̐؂�ւ�������
        if (CheckHitKey(key))
        {
            //����������
            InitKeyData(data, UNINPUT | NOWUNINPUT, NOWINPUT);

            //�J�E���g�����Z���ďu�ԂƍŒ��̔�����Ƃ�
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
            //����������
            InitKeyData(data, ONINPUT | NOWINPUT, NOWUNINPUT);

            //�J�E���g�����Z���ďu�ԂƍŒ��̔�����Ƃ�
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
    //�t���O�Ɠ����X�e�[�^�X��������J�E���g������
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
    //�����Ȃ�
}

KeyStatus::~KeyStatus()
{
    //�f�[�^�̒��g������Ȃ�폜
    if (keyData.size() > 0)
    {
        keyData.clear();
    }
}