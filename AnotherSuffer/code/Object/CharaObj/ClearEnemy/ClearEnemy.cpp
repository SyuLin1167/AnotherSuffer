#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include "ClearEnemy.h"

static constexpr float CAPSULE_RAD = 8.0f;
static constexpr float MAX_MOVE_POS = 80.0f;
static constexpr float MOVE_SPEED = 20.0f;
static constexpr int HEAD_FRAME = 10;      //頭部フレーム

ClearEnemy::ClearEnemy()
    :CharaObjBase(ObjTag.ENEMY)
{
    //モデル読み込み
    objHandle = MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(modelData.GetString()));
    objDir = VGet(-1, 0, 0);
    objScale = VGet(0.15f, 0.15f, 0.15f);
    objLocalPos=VGet(130, 0, 80);
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));

    AssetManager::MotionInstance()->StartMotion(this,
        AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

    moveSpeed = MOVE_SPEED;
    isMove = true;

    clearGraph = AssetManager::GraphInstance()->GetHandle(AssetManager::GraphInstance()->
        GetJsonData()[objTag.c_str()][jsondata::objKey.clear.c_str()].GetString());
}

ClearEnemy::~ClearEnemy()
{
    //処理なし
}

void ClearEnemy::Update(const float deltaTime)
{

    AssetManager::MotionInstance()->AddMotionTime(this, deltaTime);

    MoveChara(deltaTime);

    //座標更新
    CalcObjPos();
    YAxisData->RotateToAim(objDir);

    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));
}

void ClearEnemy::MoveChara(const float deltaTime)
{
    if (MAX_MOVE_POS < objPos.x)
    {
        objLocalPos.x -= moveSpeed * deltaTime;
    }
    else
    {
        isMove = false;
        objLocalPos.x = MAX_MOVE_POS;
        AssetManager::MotionInstance()->StartMotion(this,
            AssetManager::MotionInstance()->GetHandle(
                AssetManager::GetFilePass(motionData[jsondata::objKey.dance.c_str()])));
    }
}

void ClearEnemy::Draw()
{
    //モデル描画
    MV1DrawModel(objHandle);

    if (!isMove)
    {
        DrawExtendGraph3D(GetObjFramePos(HEAD_FRAME).x, GetObjFramePos(HEAD_FRAME).y+25,
            GetObjFramePos(HEAD_FRAME).z, 0.05f, 0.05f, clearGraph, true);
    }
}


