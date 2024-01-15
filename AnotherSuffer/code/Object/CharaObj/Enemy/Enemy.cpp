#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include"../../../Object/StageObj/StageManager/StageManager.h"
#include "Enemy.h"

Enemy::Enemy()
    :CharaObjBase(ObjTag.ENEMY)
{
    //���f���ǂݍ���
    objHandle = AssetManager::ModelInstance()->GetHandle(modelData.GetString());
    objDir = VGet(0, 0, -1);
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

Enemy::~Enemy()
{
    //�����Ȃ�
}

void Enemy::Update(const float deltaTime)
{
    StageManager::GetStageData();
}

void Enemy::MoveChara(const float deltaTime)
{

}

void Enemy::Draw()
{

}