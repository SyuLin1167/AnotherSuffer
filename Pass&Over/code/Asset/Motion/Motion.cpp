#include<DxLib.h>

#include "../AssetManager/AssetManager.h"
#include"../Model/Model.h"
#include "Motion.h"

Motion::Motion()
    :attachedIndex(0)
{
    assetType = "motion";

    //jsonファイル読み込み
    jsonFile = "../json/MotionData.json";
    LoadJsonFile(jsonFile);

    //オブジェクト分データ追加
    Model* model = AssetManager::ModelInstance();
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        modelHandle = model->GetHandle(objType->value.GetString());
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
        attachedIndex = MV1AttachAnim(modelHandle, param.index, handle, TRUE);
        param.totalTime = MV1GetAnimTotalTime(handle, param.index);
        MV1DetachAnim(modelHandle, attachedIndex);

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

