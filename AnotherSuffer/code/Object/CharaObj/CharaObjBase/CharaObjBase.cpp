#include<DxLib.h>

#include"../../ObjBase/ObjBase.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../Math/Math.h"
#include "CharaObjBase.h"

static constexpr float SIMILAR_ANGLE = 0.999f;     //相似角
const float CharaObjBase::ROTATE_SPEED = 3.0f;     //回転速度

using namespace math;

CharaObjBase::CharaObjBase(std::string tag)
    :ObjBase(tag)
    , isMove(false)
    , moveSpeed()
    , nowRotate(false)
    , modelData(GetAssetPathData(AssetManager::ModelInstance()))
    , soundData(GetAssetPathData(AssetManager::SoundInstance()))
    , motionData(GetAssetPathData(AssetManager::MotionInstance()))
    , aimDir()
    , rotRad()
    , rotXRad()
    , rotYRad(-DX_PI_F / 2.0f)
    , rotZRad()
{
    rotXMat = MGetRotX(rotXRad);
    rotYMat = MGetRotY(rotYRad);
    rotZMat = MGetRotZ(rotZRad);
    rotateYMat = MMult(MGetScale(objScale), rotYMat);
}

CharaObjBase::~CharaObjBase()
{
    //処理なし
}

void CharaObjBase::RotateYAxis(const VECTOR dir, float velocity)
{
    //現方向が目標方向でなければ回転中にする
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //回転中なら
    if (nowRotate)
    {
        //目標方向付近まで回転
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE )
        {
            //回転方向算出してベクトルと行列の両方を回転させる
            rotYRad += CalcRotDirY(velocity);
            objDir = VTransform(objDir, rotYMat);
            rotateYMat = MGetRotY(rotYRad);
        }
        else
        {
            //目標方向にして回転停止
            rotateYMat =  MGetRotVec2(objDir, aimDir);
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

void CharaObjBase::RotateXAxis(const VECTOR dir, float velocity)
{
    aimDir = dir;
    float rotDir = CalcRotDirX(velocity);

    //回転方向算出してベクトルと行列の両方を回転させる
    rotXRad += rotDir;
    objDir = VTransform(objDir, rotXMat);
    rotateXMat = MGetRotX(rotXRad);
}

void CharaObjBase::RotateToAimXAxis(const VECTOR dir, float velocity)
{
    //現方向が目標方向でなければ回転中にする
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //回転中なら
    if (nowRotate)
    {
        //目標方向付近まで回転
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE)
        {
            //回転方向算出してベクトルと行列の両方を回転させる
            rotXRad += CalcRotDirX(velocity);
            objDir = VTransform(objDir, rotXMat);
            rotateXMat = MGetRotX(rotXRad);
        }
        else
        {
            //目標方向にして回転停止
            rotateXMat =  MGetRotVec2(objDir, aimDir);
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

void CharaObjBase::RotateZAxis(const VECTOR dir, float velocity)
{
    aimDir = dir;
    float rotDir = CalcRotDirZ(velocity);

    //回転方向算出してベクトルと行列の両方を回転させる
    rotZRad += rotDir;
    objDir = VTransform(objDir, rotZMat);
    rotateZMat = MGetRotZ(rotZRad);
}

void CharaObjBase::RotateToAimZAxis(const VECTOR dir, float velocity)
{
    //現方向が目標方向でなければ回転中にする
    aimDir = dir;
    if (objDir != aimDir)
    {
        nowRotate = true;
    }

    //回転中なら
    if (nowRotate)
    {
        //目標方向付近まで回転
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE)
        {
            //回転方向算出してベクトルと行列の両方を回転させる
            rotZRad += CalcRotDirZ(velocity);
            objDir = VTransform(objDir, rotZMat);
            rotateZMat = MGetRotZ(rotZRad);
        }
        else
        {
            //目標方向にして回転停止
            rotateZMat = MGetRotVec2(objDir, aimDir);
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

float CharaObjBase::CalcRotDirX(float velocity)
{
    //ラジアン角にして回転行列へ変換
    rotRad = math::DegToRad(velocity);
    rotXMat = MGetRotX(rotRad);

    //回転方向を算出
    if (VCross(objDir, aimDir).y < 0)
    {
        rotXMat = MTranspose(rotXMat);
        return -rotRad;
    }
    return rotRad;
}

float CharaObjBase::CalcRotDirY(float velocity)
{
    //ラジアン角にして回転行列へ変換
    rotRad = math::DegToRad(velocity);
    rotYMat = MGetRotY(rotRad);

    //回転方向を算出
    if (VCross(objDir, aimDir).y < 0)
    {
        rotYMat = MTranspose(rotYMat);
        return -rotRad;
    }
    return rotRad;
}

float CharaObjBase::CalcRotDirZ(float velocity)
{
    //ラジアン角にして回転行列へ変換
    rotRad = math::DegToRad(velocity);
    rotZMat = MGetRotZ(rotRad);

    //回転方向を算出
    if (VCross(objDir, aimDir).y < 0)
    {
        rotZMat = MTranspose(rotZMat);
        return -rotRad;
    }
    return rotRad;
}

rapidjson::Value& CharaObjBase::GetAssetPathData(AssetBase* asset)
{
    //任意のアセットデータにオブジェクトがいたらパスデータ初期化
    auto& jsonData = asset->GetJsonData();
    if (jsonData.HasMember(objTag.c_str()))
    {
        return jsonData[objTag.c_str()];
    }

    //なかったらからの値を返す
    rapidjson::Value null;
    null.Set(-1);
    return null;
}

