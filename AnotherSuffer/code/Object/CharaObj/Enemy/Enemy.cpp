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
static constexpr float CLIP_BOX_SIZE = 100.0f;     //�؂蔲���{�b�N�X�T�C�Y

Enemy::Enemy()
    :CharaObjBase(ObjTag.ENEMY)
    , timer()
    , clipBoxScale()
    , clipBoxPos1()
    , clipBoxPos2()
{
    //���f���ǂݍ���
    objHandle = MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(modelData.GetString()));
    objDir = VGet(0, 0, -1);
    auto stage=StageManager::GetStageData();
    objLocalPos = stage[15][15].pos;
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(YAxisData->GetRotateMat(), MGetTranslate(objPos)));

    //�����蔻��̓J�v�Z���^
    capsule = new Capsule(VAdd(objPos, VGet(0, 6, 0)), VAdd(objPos, VGet(0, 30, 0)), 6.0f);
    CollisionManager::AddCol(this, capsule);
    line = new Line(objPos,objPos);
    CollisionManager::AddCol(this, line);

    //�o�H�T���ݒ�
    astar.reset(new Astar);
    player = ObjManager::GetObj(ObjTag.PLAYER,0);

    ResetNode(objPos, &start);
    ResetNode(player->GetObjPos(), &goal);
    path = astar->Algorithm(start, goal);

    moveSpeed = 40.0f;
}

Enemy::~Enemy()
{
    path.clear();
}

void Enemy::Update(const float deltaTime)
{
    //���Z�b�g���Ԃ��ƂɌo�H�̍č\�����s��
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
        MoveChara(deltaTime);
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
                objLocalPos = VAdd(objLocalPos, VScale(vec, moveSpeed * deltaTime));
                YAxisData->RotateToAim(vec, 10.0f);
                break;
            }
            else
            {
                //�ڕW�n�_�Ɉ�苗���߂Â�����A���̒n�_�Ɉړ�
                path.erase(path.begin());
            }
        }
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

            //�ʏ�͓���
            isMove = true;
            if (!line->OnCollisionWithMesh(obj->GetColModel()))
            {
                ViewClipBox();
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
#endif // _DEBUG
}