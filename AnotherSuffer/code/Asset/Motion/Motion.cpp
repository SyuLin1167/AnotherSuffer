#include<DxLib.h>

#include"../../Object/ObjBase/ObjBase.h"
#include "../AssetManager/AssetManager.h"
#include"../Model/Model.h"
#include "Motion.h"

Motion::Motion(class Model* model)
    :modelHandle(-1)
    ,attachedIndex()
{
    //jsonファイル読み込み
    jsonFile = "../json/MotionData.json";
    LoadJsonFile(jsonFile);

    //オブジェクト分データ追加
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
    //仮ハンドル初期化
    holdHandle = -1;
    dupHandle = -1;

    //ファイルが見つからなかったらハンドルを複製して追加
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
    //ハンドル検索
    auto handle = GetHandle(key[jsondata::dataKey.pass.c_str()].GetString());
    auto findData = motionData.find(handle);

    //見つからなかったらモーションデータ追加
    if (findData == motionData.end())
    {
        MotionParam param = {};
        param.isLoop = key[jsondata::dataKey.loop.c_str()].GetBool();
        param.playSpeed = key[jsondata::dataKey.speed.c_str()].GetFloat();

        //データ初期化のためアタッチ
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
    //処理なし
}

void Motion::DeleteHandle()
{
    //ハンドルとデータ解放
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
    //再生速度に合わせて加算
    if (IsPlaying(nowHandle[obj]))
    {
        motionData[nowHandle[obj]].nowMotionTime += motionData[nowHandle[obj]].playSpeed * deltaTime;

        //ループ再生
        if (motionData[nowHandle[obj]].isLoop &&
            motionData[nowHandle[obj]].nowMotionTime > motionData[nowHandle[obj]].totalTime)
        {
            motionData[nowHandle[obj]].nowMotionTime = 0.0f;
        }

        //モーション時間アタッチ
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

    //モーション切り替え
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

        //時間をリセットして再生
        motionData[nowHandle[obj]].nowMotionTime = 0.0f;
        MV1SetAttachAnimTime(modelHandle, attachedIndex[modelHandle], motionData[nowHandle[obj]].nowMotionTime);
    }
}

void Motion::StopMotion(int handle)
{
    //ハンドルを検索
    auto findHandle = motionData.find(handle);
    if (findHandle != motionData.end())
    {
        //見つかったらモーション時間を総再生時間にする
        motionData[handle].nowMotionTime = motionData[handle].totalTime;
    }
}

bool Motion::IsPlaying(int handle)
{
    //ループ再生不可でモーションが再生しきったら停止中
    if (!motionData[handle].isLoop &&
        motionData[handle].nowMotionTime > motionData[handle].totalTime)
    {
        return false;
    }

    //基本は再生中
    return true;
}

