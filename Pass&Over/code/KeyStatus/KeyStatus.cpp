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

bool IsInput(int key)
{
    //���͂��Ă���true���Ă��Ȃ�������false��Ԃ�
    if (key != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}