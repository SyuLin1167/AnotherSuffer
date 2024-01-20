#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "Ball.h"

static constexpr float SPEED = 0.1f;
static constexpr float MAX_SPEED = 40.0f;
static constexpr float MIN_SPEED = 0.0f;

Ball::Ball()
    :CharaObjBase(ObjTag.BALL)
    , moveVel()
{
    //���f���ǂݍ���
    objHandle = AssetManager::ModelInstance()->GetHandle(modelData.GetString());
    objScale = VGet(0.08f, 0.08f, 0.08f);
    objDir = VGet(-1, 0, -1);
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

    //�ړ����x�͑��鑬�x
    moveSpeed = MIN_SPEED;

    //�����蔻��̓J�v�Z���^
    capsule = new Capsule(VAdd(objPos, VGet(0, 6, 0)), VAdd(objPos, VGet(0, 30, 0)), 7.0f);
    CollisionManager::AddCol(this, capsule);
}

Ball::~Ball()
{
    //�����Ȃ�
}

void Ball::Update(const float deltaTime)
{
    a += deltaTime;

    //�L�����ړ�
    MoveChara(deltaTime);

    //���W�X�V
    CalcObjPos();

    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Ball::MoveChara(const float deltaTime)
{
    //��~���ɂ���
    isMove = false;

    //�L�[���͂ɂ��ړ���
    //moveVel = VGet(0, 0, 0);
    MoveByKey(KEY_INPUT_W, VGet(1,0,0), deltaTime);
    MoveByKey(KEY_INPUT_S, VGet(-1,0,0), deltaTime);
    MoveByKey(KEY_INPUT_A, VGet(0,0,1), deltaTime);
    MoveByKey(KEY_INPUT_D, VGet(0,0,-1), deltaTime);
    moveVel.y = 0;

    if (isMove)
    {
        //���W�E�����̎Z�o
        moveSpeed += SPEED;
        if (moveSpeed > MAX_SPEED)
        {
            moveSpeed = MAX_SPEED;
        }
        objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));
        RotateYAxis(moveVel, VSize(moveVel) * 10.0f);
    }
}

void Ball::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //�L�[�����͂���Ă�����ړ����̎��s
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel = VNorm(VAdd(moveVel, dir));

        //���쒆�ɂ���
        isMove = true;
    }
}

void Ball::OnCollisionEnter(ObjBase* colObj)
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
        }
    }

    //���W�X�V
    CalcObjPos();
    capsule->Update(objPos);

    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Ball::Draw()
{
    //���f���`��
    MV1DrawModel(objHandle);

#ifdef _DEBUG
    //�����蔻��`��
    capsule->DrawCapsule();

    //���������|���S��
    for (int i = 0; i < colInfo.HitNum; i++)
    {
        DrawTriangle3D(
            colInfo.Dim[i].Position[0],
            colInfo.Dim[i].Position[1],
            colInfo.Dim[i].Position[2], GetColor(0, 255, 255), TRUE);
    }

    DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", test);
#endif // _DEBUG
}