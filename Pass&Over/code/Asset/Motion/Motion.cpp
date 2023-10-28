#include<DxLib.h>

#include "Motion.h"

Motion::Motion()
{
    assetType = "motion";

    //json�t�@�C���ǂݍ���
    jsonFile = "../json/MotionData.json";
    LoadJsonFile(jsonFile);

    //�I�u�W�F�N�g���f�[�^�ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        for (rapidjson::Value::ConstMemberIterator motionType = objType->value.MemberBegin();
            motionType != objType->value.MemberEnd(); motionType++)
        {
            AddHandle(motionType->value[jsondata::dataKey.pass.c_str()].GetString());
            AddData(motionType->value);
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
    //�n���h������
    auto handle = GetHandle(key[jsondata::dataKey.pass.c_str()].GetString());
    auto findData = motionData.find(handle);

    //������Ȃ������烂�[�V�����f�[�^�ǉ�
    if (findData == motionData.end())
    {
        MotionParam param = {};
        param.index=MV1GetAnimNum()


        param.isLoop = key[jsondata::dataKey.loop.c_str()].GetBool();
        param.playSpeed = key[jsondata::dataKey.speed.c_str()].GetFloat();

        motionData.emplace(handle, param);
    }
}

Motion::MotionParam::MotionParam()
    :isLoop(false)
    ,playSpeed(0)
{
    //�����Ȃ�
}

