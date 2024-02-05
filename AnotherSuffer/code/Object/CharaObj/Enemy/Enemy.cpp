#include<math.h>
#include<stack>

#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Object/StageObj/StageManager/StageManager.h"
#include "Enemy.h"
#include"../../../Collision/Capsule/Capsule.h"
#include"../../../Collision/Line/Line.h"
#include"../Astar/Astar.h"

static constexpr float RESET_TIME = 2.0f;   //���Z�b�g����
static constexpr float MAX_DISTANCE = 1000.0f;  //�ő勗��
static constexpr float CLEAR_DISTANCE = 0.0f;   //��������
static constexpr float CLIP_BOX_SIZE = 150.0f;     //�؂蔲���{�b�N�X�T�C�Y
static constexpr float MOVE_SPEED = 70.0f;
static constexpr float CAPSULE_RAD = 8.0f;

Enemy::Enemy()
    :CharaObjBase(ObjTag.ENEMY)
    , timer()
    , clipBoxScale()
    , clipBoxPos1()
    , clipBoxPos2()
    , isScream(false)
{
    //���f���ǂݍ���
    objHandle = MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(modelData.GetString()));
    objDir = VGet(0, 0, -1);
    objScale = VGet(0.15f, 0.15f, 0.15f);
    auto stage=StageManager::GetStageData();
    objLocalPos = stage[15][15].pos;
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));

    AssetManager::MotionInstance()->StartMotion(this,
        AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

    //�����蔻��̓J�v�Z���^
    capsule = new Capsule(VAdd(objWorldPos, VGet(0, 6, 0)), VAdd(objWorldPos, VGet(0, 30, 0)), CAPSULE_RAD);
    capsule->Update(objPos);
    CollisionManager::AddCol(this, capsule);
    line = new Line(objWorldPos, objWorldPos);
    CollisionManager::AddCol(this, line);

    //�o�H�T���ݒ�
    astar.reset(new Astar);
    player = ObjManager::GetObj(ObjTag.PLAYER,0);

    ResetNode(objPos, &start);
    ResetNode(player->GetObjPos(), &goal);
    path = astar->Algorithm(start, goal);

}

Enemy::~Enemy()
{
    path.clear();
}

void Enemy::Update(const float deltaTime)
{
    //�c���ǐ��ɉ����ĉ���
    moveSpeed = MOVE_SPEED - (StageManager::GetBarricadeNum() * 1.5f);

    //���Z�b�g���Ԃ��ƂɌo�H�̍č\�����s��
    if (!isScream)
    {
        timer += deltaTime;
        if (timer >= RESET_TIME)
        {
            path.clear();
            ResetNode(objPos, &start);
            ResetNode(player->GetObjPos(), &goal);
            path = astar->Algorithm(start, goal);
            timer = 0;
        }


        if (isMove)
        {
            AssetManager::MotionInstance()->AddMotionTime(this, deltaTime);
            MoveChara(deltaTime);
        }

        //�ʏ�͓���
        isMove = true;
        ViewClipBox();
    }
    else
    {
        AssetManager::MotionInstance()->StartMotion(this,
            AssetManager::MotionInstance()->GetHandle(
                AssetManager::GetFilePass(motionData[jsondata::objKey.scream.c_str()])));

        AssetManager::MotionInstance()->AddMotionTime(this, deltaTime);

        if (!AssetManager::MotionInstance()->IsPlaying(AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.scream.c_str()]))))
        {
            isAlive = false;
        }
    }

    //���W�X�V
    CalcObjPos();

    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));

}

void Enemy::MoveChara(const float deltaTime)
{
    //�o�H���󂶂�Ȃ�������
    if (!path.empty())
    {
        //�o�H�ʂ�ɐi��
        auto stage = StageManager::GetStageData();
        for (auto& point : path)
        {
            float dis = abs(VSize(VSub(stage[point.first][point.second].pos, objPos)));
            if (dis > 10.0f)
            {
                //�ڕW�n�_�Ɉړ�
                VECTOR vec = VNorm(VSub(stage[point.first][point.second].pos, objPos));
                vec.y = 0;
                objLocalPos = VAdd(objLocalPos, VScale(vec, moveSpeed * deltaTime));
                YAxisData->RotateToAim(vec);
                break;
            }
            else
            {
                //�ڕW�n�_�Ɉ�苗���߂Â�����A���̒n�_�Ɉړ�
                path.erase(path.begin());
            }
        }
    }
    else
    {
        VECTOR vec = VNorm(VSub(player->GetObjPos(), objPos));
        objLocalPos = VAdd(objLocalPos, VScale(vec, moveSpeed * deltaTime));
    }
}

void Enemy::ViewClipBox()
{
    //����ɃN���b�v�{�b�N�X���������瓮���Ȃ�
    clipBoxScale = VScale(objScale, CLIP_BOX_SIZE);
    clipBoxPos1 = VSub(objPos, clipBoxScale);
    clipBoxPos2 = VAdd(objPos, VAdd(clipBoxScale, VGet(0, clipBoxScale.y, 0)));
    if (!CheckCameraViewClip_Box(clipBoxPos1, clipBoxPos2))
    {
        isMove = false;
    }
}

void Enemy::OnCollisionEnter(ObjBase* colObj)
{
    //�����蔻�菈��
    for (auto& obj : CollisionManager::GetCol(colObj))
    {
        if (obj->GetColTag() == ColTag.MODEL)
        {
            if (capsule->OnCollisionWithMesh(obj->GetColModel()))
            {
                objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh());

                MV1CollResultPolyDimTerminate(capsule->GetColInfoDim());
            }
            if (line->OnCollisionWithMesh(obj->GetColModel()))
            {
                isMove = true;
            }
            continue;
        }
        if (obj->GetColTag() == ColTag.CAPSULE)
        {
            if (capsule->OnCollisionWithCapsule(obj->GetWorldStartPos(), obj->GetWorldEndPos(), obj->GetRadius() * 2.5f) || !player->IsVisible())
            {
                isScream = true;
                YAxisData->RotateToAim(VNorm(VSub(player->GetObjPos(), objPos)));
            }
        }
    }

    //���W�X�V
    CalcObjPos();
    capsule->Update(objPos);
    line->Update(objPos, player->GetObjPos());

    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));
}

void Enemy::ResetNode(VECTOR pos, std::pair<int, int>* node)
{
    //����������
    float nowDistance = MAX_DISTANCE;
    float distance = CLEAR_DISTANCE;

    //�����T��
    for (auto& rowData : StageManager::GetStageData())
    {
        //���݂̋������߂������ɂ���Ȃ�m�[�h��������
        distance = abs(rowData.second[0].pos.z - pos.x);
        if (nowDistance > distance)
        {
            nowDistance = distance;
            node->first = rowData.first;
        }
        else
        {
            //�����ōŒZ�m�[�h�����܂�����c���T��
            nowDistance = MAX_DISTANCE;
            for (auto& colData : rowData.second)
            {
                //���݂̋������߂������ɂ���Ȃ�m�[�h��������
                distance = abs(colData.second.pos.x - pos.z);
                if (nowDistance > distance)
                {
                    nowDistance = distance;
                    node->second = colData.first;
                }
                else
                {
                    //�c���ōŒZ�m�[�h�����܂�����T���I��
                    break;
                }
            }
            break;
        }
    }
}

void Enemy::Draw()
{
    //���f���`��
    MV1DrawModel(objHandle);

#ifdef _DEBUG
    if (path.empty()) {
        DrawFormatString(0, 50, GetColor(255, 255, 255), "�S�[���ɓ��B�ł��܂���ł����B");
    }
    else {
        DrawFormatString(0, 100, GetColor(255, 255, 255), "�ŒZ�o�H: ");
        for (const auto& point : path) {
            DrawFormatString(point.second * 50, point.first * 50 + 200, GetColor(255, 255, 255), "(%d,%d)", point.first, point.second);
        }
    }

    //�����蔻��`��
    capsule->DrawCapsule();

    DrawFormatString(800, 0, GetColor(255, 255, 255), "�G���W%f,%f\n�ړ����x%f", capsule->GetWorldStartPos().x, capsule->GetWorldStartPos().z,moveSpeed);
#endif // _DEBUG
}