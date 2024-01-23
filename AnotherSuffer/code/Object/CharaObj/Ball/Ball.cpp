#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "Ball.h"

static constexpr float SPEED = 1.0f;
static constexpr float MAX_SPEED = 40.0f;
static constexpr float MIN_SPEED = 0.0f;

Ball::Ball()
    :CharaObjBase(ObjTag.BALL)
    , moveVel(VGet(1,0,0))
{
    //���f���ǂݍ���
    objHandle = AssetManager::ModelInstance()->GetHandle(modelData.GetString());
    objScale = VGet(0.08f, 0.08f, 0.08f);
    objDir = VGet(-1, 0, -1);
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale),rotateZMat), MGetTranslate(objPos)));

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
    objPos.y = capsule->GetRadius();
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), RotateVel()), MGetTranslate(objPos)));
}

void Ball::MoveChara(const float deltaTime)
{
    //��~���ɂ���
    isMove = false;

    //�L�[���͂ɂ��ړ���
    MoveByKey(KEY_INPUT_W, VGet(1.0f,0,0), deltaTime);
    MoveByKey(KEY_INPUT_S, VGet(-1.0f,0,0), deltaTime);
    MoveByKey(KEY_INPUT_A, VGet(0,0,1.0f), deltaTime);
    MoveByKey(KEY_INPUT_D, VGet(0,0,-1.0f), deltaTime);
    moveVel = VNorm(moveVel);
    moveVel.y = 0;

    if (isMove)
    {
        //���W�E�����̎Z�o
        moveSpeed += SPEED;
        if (moveSpeed > MAX_SPEED)
        {
            moveSpeed = MAX_SPEED;
        }
    }
    else
    {
        moveSpeed *= 0.9f;
        if (moveSpeed < MIN_SPEED)
        {
            moveSpeed = MIN_SPEED;
        }
    }
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));

}

void Ball::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //�L�[�����͂���Ă�����ړ����̎��s
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel =VAdd(moveVel, dir);

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
                moveVel = VScale(moveVel, -1);
                MV1CollResultPolyDimTerminate(capsule->GetColInfoDim());
            }
        }
    }

    //���W�X�V
    CalcObjPos();
    capsule->Update(objPos);

    //�s��Ń��f���̓���
    //MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
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

    DrawFormatString(20, 800, GetColor(255, 255, 255), "%f,%f,%f", moveVel.x, moveVel.y, moveVel.z);
#endif // _DEBUG
}

MATRIX Ball::RotateVel()
{
    if (static_cast<int>(abs(moveVel.z)) > 0)
    {
        RotateXAxis(moveVel, VSize(moveVel) * moveSpeed / 8.0f);
        if (objDir.z>0)
        {
            return rotateXMat;
        }
        else
        {
            return MInverse(rotateXMat);
        }
    }
    if (static_cast<int>(abs(moveVel.x)) > 0)
    {
        RotateZAxis(moveVel, VSize(moveVel) * moveSpeed / 8.0f);
        return rotateZMat;
    }
    return MGetIdent();
}
