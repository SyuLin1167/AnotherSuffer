#include<DxLib.h>

#include "../AssetManager/AssetManager.h"
#include"../Model/Model.h"
#include "Motion.h"

Motion::Motion(class Model* model)
    :modelHandle(-1)
    , nowMotionTime(0)
    , nowHandle(-1)
    ,attachedIndex(0)
{
    assetType = "motion";

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
    , playSpeed(0)
    , index(0)
    , totalTime(0)
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
    motionData.clear();
}

void Motion::AddMotionTime(const float deltaTime)
{
    //再生速度に合わせて加算
    if (nowHandle && IsPlaying())
    {
        nowMotionTime += motionData[nowHandle].playSpeed * deltaTime;

        //ループ再生処理
        if (motionData[nowHandle].isLoop &&
            nowMotionTime > motionData[nowHandle].totalTime)
        {
            nowMotionTime = 0.0f;
        }

        //モーション時間アタッチ
        MV1SetAttachAnimTime(modelHandle, attachedIndex[modelHandle], nowMotionTime);
    }
}

void Motion::StartMotion(int model, int handle)
{
    //モーション切り替え
    modelHandle = model;
    if (handle != nowHandle)
    {
        nowHandle = handle;
        if (nowHandle != -1)
        {
            MV1DetachAnim(modelHandle, attachedIndex[modelHandle]);
        }
        attachedIndex[modelHandle] = MV1AttachAnim(modelHandle, motionData[nowHandle].index,
            nowHandle, TRUE);
    }
    //時間をリセットして再生
    nowMotionTime = 0.0f;
    MV1SetAttachAnimTime(modelHandle, attachedIndex[modelHandle], nowMotionTime);
}

void Motion::StopMotion()
{
    //モーション時間を総再生時間にする
    nowMotionTime = motionData[nowHandle].totalTime;
}

bool Motion::IsPlaying()
{
    //ループ再生不可でモーションが再生しきったら停止中
    if (!motionData[nowHandle].isLoop &&
        nowMotionTime > motionData[nowHandle].totalTime)
    {
        return false;
    }

    //基本は再生中
    return true;
}

