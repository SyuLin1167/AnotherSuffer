#include<DxLib.h>

#include"../../Object/ObjBase/ObjBase.h"
#include "../AssetManager/AssetManager.h"
#include"../Model/Model.h"
#include "Motion.h"

Motion::Motion(class Model* model)
    :modelHandle(-1)
    ,attachedIndex()
{
    //json�t�@�C���ǂݍ���
    jsonFile = "../json/MotionData.json";
    LoadJsonFile(jsonFile);

    //�I�u�W�F�N�g���f�[�^�ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        assert(model);
        modelHandle = model->GetHandle(model->GetJsonData()[objType->name.GetString()].GetString());
        for (rapidjson::Value::ConstMemberIterator motionType = objType->value.MemberBegin();
            motionType != objType->value.MemberEnd(); motionType++)
        {
            AddHandle(motionType->value[jsondata::dataKey.pass.c_str()].GetString());
            AddData(motionType->value);
        }
    }
    modelHandle = -1;
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
        param.isLoop = key[jsondata::dataKey.loop.c_str()].GetBool();
        param.playSpeed = key[jsondata::dataKey.speed.c_str()].GetFloat();

        //�f�[�^�������̂��߃A�^�b�`
        param.index = MV1GetAnimNum(modelHandle) - 1;
        attachedIndex.emplace(modelHandle, 0);
        attachedIndex[modelHandle] = MV1AttachAnim(modelHandle, param.index, handle, TRUE);
        param.totalTime = MV1GetAnimTotalTime(handle, param.index);
        MV1DetachAnim(modelHandle, attachedIndex[modelHandle]);

        motionData.emplace(handle, param);
    }
}

Motion::MotionParam::MotionParam()
    : isLoop(false)
    , playSpeed()
    , index()
    , nowMotionTime()
    , totalTime()
{
    //�����Ȃ�
}

void Motion::DeleteHandle()
{
    //�n���h���ƃf�[�^���
    for (auto& iter : handle)
    {
        DeleteSoundMem(iter.second);
    }
    handle.clear();
    nowHandle.clear();
    motionData.clear();
}

void Motion::AddMotionTime(class ObjBase* obj, const float deltaTime)
{
    //�Đ����x�ɍ��킹�ĉ��Z
    if (IsPlaying(nowHandle[obj]))
    {
        motionData[nowHandle[obj]].nowMotionTime += motionData[nowHandle[obj]].playSpeed * deltaTime;

        //���[�v�Đ�
        if (motionData[nowHandle[obj]].isLoop &&
            motionData[nowHandle[obj]].nowMotionTime > motionData[nowHandle[obj]].totalTime)
        {
            motionData[nowHandle[obj]].nowMotionTime = 0.0f;
        }

        //���[�V�������ԃA�^�b�`
        MV1SetAttachAnimTime(obj->GetObjHandle(), attachedIndex[modelHandle], motionData[nowHandle[obj]].nowMotionTime);
    }
}

void Motion::StartMotion(class ObjBase* obj, int handle)
{
    auto findHandle = nowHandle.find(obj);
    if (findHandle == nowHandle.end())
    {
        nowHandle.emplace(obj, -1);
    }

    //���[�V�����؂�ւ�
    modelHandle = obj->GetObjHandle();
    if (nowHandle[obj] != handle)
    {
        nowHandle[obj] = handle;
        if (nowHandle[obj] != -1)
        {
            MV1DetachAnim(modelHandle, attachedIndex[modelHandle]);
        }
        attachedIndex[modelHandle] = MV1AttachAnim(modelHandle, motionData[nowHandle[obj]].index,
            nowHandle[obj], TRUE);

        //���Ԃ����Z�b�g���čĐ�
        motionData[nowHandle[obj]].nowMotionTime = 0.0f;
        MV1SetAttachAnimTime(modelHandle, attachedIndex[modelHandle], motionData[nowHandle[obj]].nowMotionTime);
    }
}

void Motion::StopMotion(int handle)
{
    //�n���h��������
    auto findHandle = motionData.find(handle);
    if (findHandle != motionData.end())
    {
        //���������烂�[�V�������Ԃ𑍍Đ����Ԃɂ���
        motionData[handle].nowMotionTime = motionData[handle].totalTime;
    }
}

bool Motion::IsPlaying(int handle)
{
    //���[�v�Đ��s�Ń��[�V�������Đ������������~��
    if (!motionData[handle].isLoop &&
        motionData[handle].nowMotionTime > motionData[handle].totalTime)
    {
        return false;
    }

    //��{�͍Đ���
    return true;
}

