#include "CollisionManager.h"
#include"../../Object/ObjManager/ObjManager.h"

std::unique_ptr<CollisionManager> CollisionManager::singleton;

CollisionManager::CollisionManager()
{
    //�t�@�C���ǂݍ���
    std::ifstream ifs("../json/ColPairData.json");

    //�t�@�C�����
    if (ifs.good())
    {
        rapidjson::IStreamWrapper isw(ifs);

        doc.ParseStream(isw);
    }
    ifs.close();
}

void CollisionManager::InitColManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        singleton.reset(new CollisionManager);
    }
}

CollisionManager::~CollisionManager()
{
    //�����Ȃ�
}

void CollisionManager::CheckCollisionPair()
{
    //�I�u�W�F�N�g�̓����蔻��g�ݍ��킹���m�F
    for (rapidjson::Value::ConstMemberIterator mainObj = singleton->doc.MemberBegin();
        mainObj != singleton->doc.MemberEnd(); mainObj++)
    {
        for (rapidjson::Value::ConstMemberIterator pairObj = mainObj->value.MemberBegin();
            pairObj != mainObj->value.MemberEnd(); pairObj++)
        {
            //�m�F�����I�u�W�F�N�g�̑g�ݍ��킹�œ����蔻��
            OnCollisionEnter(mainObj->name.GetString(), pairObj->name.GetString());
        }
    }
}

void CollisionManager::OnCollisionEnter(std::string mainObjTag, std::string pairObjTag)
{
    //�g�ݍ��킹�ǂ���ɓ����蔻����s
    for (auto& colMain : ObjManager::GetObj(mainObjTag))
    {
        for (auto& colPair : ObjManager::GetObj(pairObjTag))
        {
            colMain->OnCollisionEnter(colPair.get());
        }
    }
}