#include "ColManager.h"
#include"../../Object/ObjManager/ObjManager.h"

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