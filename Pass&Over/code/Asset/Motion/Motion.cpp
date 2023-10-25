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