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
    :inputState(0)
{
}

bool IsInput(int key)
{
    //���͂��Ă���true���Ă��Ȃ�������false��Ԃ�
    if (key != 0)
    {
        return true;
    }

    return false;
}