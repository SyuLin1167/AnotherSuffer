#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "TitleEnemy.h"


static constexpr float CAPSULE_RAD = 8.0f;
static const VECTOR FIRST_POS = VGet(72, 0, 29);

TitleEnemy::TitleEnemy()
    :CharaObjBase(ObjTag.ENEMY)
{
    //モデル読み込み
    objHandle = MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(modelData.GetString()));
    objDir = VGet(-1, 0, 0);
    objScale = VGet(0.13f, 0.13f, 0.13f);
    objLocalPos = FIRST_POS;
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));


    AssetManager::MotionInstance()->StartMotion(this,
        AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.hide.c_str()])));
    AssetManager::MotionInstance()->StartMotion(this,
        AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.look.c_str()])));

    //当たり判定はカプセル型
    capsule = new Capsule(VAdd(objWorldPos, VGet(0, 6, 0)), VAdd(objWorldPos, VGet(0, 30, 0)), CAPSULE_RAD);
    capsule->Update(objPos);
    CollisionManager::AddCol(this, capsule);
}

TitleEnemy::~TitleEnemy()
{
    //処理なし
}

void TitleEnemy::Update(const float deltaTime)
{
    AssetManager::MotionInstance()->AddMotionTime(this, deltaTime);
    MoveChara(deltaTime);
    YAxisData->RotateToAim(objDir);
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));
}

void TitleEnemy::MoveChara(const float deltaTime)
{
    if (!AssetManager::MotionInstance()->IsPlaying(AssetManager::MotionInstance()->GetHandle(
        AssetManager::GetFilePass(motionData[jsondata::objKey.hide.c_str()]))))
    {
        isVisible = false;
    }
}

void TitleEnemy::OnCollisionEnter(class ObjBase* colObj)
{
    //当たり判定処理
    for (auto& obj : CollisionManager::GetCol(colObj))
    {
        if (obj->GetColTag() == ColTag.CAPSULE)
        {
            if (capsule->OnCollisionWithCapsule(obj->GetWorldStartPos(), obj->GetWorldEndPos(), obj->GetRadius()))
            {
                AssetManager::MotionInstance()->StartMotion(this,
                    AssetManager::MotionInstance()->GetHandle(
                        AssetManager::GetFilePass(motionData[jsondata::objKey.hide.c_str()])));
            }
        }
    }
}

void TitleEnemy::Draw()
{
    //モデル描画
    MV1DrawModel(objHandle);
}