#include "ColManager.h"

std::unique_ptr<ColManager> ColManager::singleton;

ColManager::ColManager()
{
    //�t�@�C���ǂݍ���
    std::ifstream ifs("../json/ColData.json");

    //�t�@�C�����
    if (ifs.good())
    {
        rapidjson::IStreamWrapper isw(ifs);

        doc.ParseStream(isw);
    }
    ifs.close();
}

void ColManager::InitColManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        singleton.reset(new ColManager);
    }
}

ColManager::~ColManager()
{
    //�����Ȃ�
}

void ColManager::CheckCollisionPair()
{
    for (rapidjson::Value::ConstMemberIterator objType =singleton->doc.MemberBegin();
        objType != singleton->doc.MemberEnd(); objType++)
    {
        for (rapidjson::Value::ConstMemberIterator motionType = objType->value.MemberBegin();
            motionType != objType->value.MemberEnd(); motionType++)
        {
        }
    }
}