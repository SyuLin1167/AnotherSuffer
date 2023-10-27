#include<DxLib.h>

#include "Motion.h"

Motion::Motion()
{
    assetType = "motion";

    //json�t�@�C���ǂݍ���
    jsonFile = "../json/MotionData.json";
    LoadJsonFile(jsonFile);

    //�n���h���ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        for (rapidjson::Value::ConstMemberIterator soundType = objType->value.MemberBegin();
            soundType != objType->value.MemberEnd(); soundType++)
        {
            AddHandle(soundType->value["pass"].GetString());
        }
    }
}

Motion::~Motion()
{
    DeleteHandle();
}

void Motion::AddHandle(const std::string fileName)
{
    //���n���h��������
    holdHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto findHandle = handle.find(fileName);
    if (findHandle == handle.end())
    {
        holdHandle = MV1LoadModel(fileName.c_str());
        dupHandle = MV1DuplicateModel(holdHandle);
        handle.emplace(fileName, dupHandle);
    }
}

void Motion::AddData(const rapidjson::Value& key)
{

}

