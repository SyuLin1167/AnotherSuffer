#include "ColManager.h"
#include"../../Object/ObjManager/ObjManager.h"

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
    for (rapidjson::Value::ConstMemberIterator mainObj =singleton->doc.MemberBegin();
        mainObj != singleton->doc.MemberEnd(); mainObj++)
    {
        for (rapidjson::Value::ConstMemberIterator pairObj = mainObj->value.MemberBegin();
            pairObj != mainObj->value.MemberEnd(); pairObj++)
        {
            for (auto& colMain:ObjManager::GetObj(mainObj->name.GetString()))
            {
                for (auto& colPair : ObjManager::GetObj(pairObj->name.GetString()))
                {
                    colMain->OnCollisionEnter(colPair.get());
                }
            }
        }
    }
}