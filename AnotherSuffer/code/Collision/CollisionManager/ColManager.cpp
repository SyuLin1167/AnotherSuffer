#include "ColManager.h"

std::unique_ptr<ColManager> ColManager::singleton;

ColManager::ColManager()
{
    //ファイル読み込み
    std::ifstream ifs("../json/ColData.json");

    //ファイル解析
    if (ifs.good())
    {
        rapidjson::IStreamWrapper isw(ifs);

        doc.ParseStream(isw);
    }
    ifs.close();
}

void ColManager::InitColManager()
{
    //自身の中身が空だったらインスタンス生成
    if (!singleton)
    {
        singleton.reset(new ColManager);
    }
}

ColManager::~ColManager()
{
    //処理なし
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