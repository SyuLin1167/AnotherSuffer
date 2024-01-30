#include"../../../KeyStatus/KeyStatus.h"
#include"../../Math/Math.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include"../../../Collision/Line/Line.h"
#include "Player.h"

static constexpr float RUN_SPEED = 40.0f;
static constexpr float CAPSULE_RAD = 7.0f;

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
    ,moveVel()
{
    //���f���ǂݍ���
    objHandle = AssetManager::ModelInstance()->GetHandle(modelData.GetString());
    objDir = VGet(0, 0, -1);
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale),YAxisData->GetRotateMat()), MGetTranslate(objPos)));

    AssetManager::MotionInstance()->StartMotion(this,
        AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));

    //�ړ����x�͑��鑬�x
    moveSpeed = RUN_SPEED;

    //�����蔻��̓J�v�Z���^
    capsule = new Capsule(VAdd(objWorldPos, VGet(0, 6, 0)), VAdd(objWorldPos, VGet(0, 30, 0)), CAPSULE_RAD);
    capsule->Update(objPos);
    CollisionManager::AddCol(this, capsule);
    line = new Line(VAdd(objPos, VGet(0, 5, 0)), VAdd(objPos, VGet(0, -5, 0)));
    CollisionManager::AddCol(this, line);

    //�����C�g
    texHandle = CreateSpotLightHandle(objPos,objDir,DX_PI_F,DX_PI_F/2, 150.0f, 0.0f, 0.0f, 0.0005f);
    test = 0;
}

Player::~Player()
{
    //�����Ȃ�
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    //�A�j���[�V�������ԍĐ�
    AssetManager::MotionInstance()->AddMotionTime(this, deltaTime);

    //�L�����ړ�
    MoveChara(deltaTime);

    //��~��
    if(!isMove)
    {
        //�ʏ펞�A�j���[�V�����Đ�
        AssetManager::MotionInstance()->StartMotion(this,
            AssetManager::MotionInstance()->GetHandle(
                AssetManager::GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
    }

    //P�L�[�������ꂽ��
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, ONINPUT))
    {
        //���S�ɂ���
        isAlive = false;

        //�T�E���h�Đ�
        AssetManager::SoundInstance()->StartSound(
        AssetManager::SoundInstance()->GetHandle(
        AssetManager::GetFilePass(soundData[jsondata::objKey.walk.c_str()])));
    }

    //���W�X�V
    CalcObjPos();
    
    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));
}

void Player::MoveChara(const float deltaTime)
{
    //��~���ɂ���
    isMove = false;

    //�J�����̌��������g�̈ړ������Ƃ���
    ObjBase* camera = ObjManager::GetObj(ObjTag.CAMERA,0);
    SetLightDirectionHandle(texHandle, camera->GetObjDir());
    SetLightPositionHandle(texHandle, camera->GetObjPos());
    VECTOR aimDir = camera->GetObjDir();
    VECTOR rightDir = VCross(VGet(0, -1, 0), aimDir);
    aimDir = VNorm(aimDir);
    aimDir.y = 0;

    //�L�[���͂ɂ��ړ���
    moveVel = VGet(0, 0, 0);
    MoveByKey(KEY_INPUT_W, aimDir, deltaTime);
    MoveByKey(KEY_INPUT_S, VScale(aimDir, -1), deltaTime);
    MoveByKey(KEY_INPUT_A, rightDir, deltaTime);
    MoveByKey(KEY_INPUT_D, VScale(rightDir, -1), deltaTime);

    //���W�E�����̎Z�o
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));
    YAxisData->RotateToAim(aimDir);
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //�L�[�����͂���Ă�����ړ����̎��s
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel = VNorm(VAdd(moveVel, dir));

        //�ړ��A�j���[�V�����Đ�
        AssetManager::MotionInstance()->StartMotion(this,
            AssetManager::MotionInstance()->GetHandle(
            AssetManager::GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //���쒆�ɂ���
        isMove = true;
    }
}

void Player::OnCollisionEnter(ObjBase* colObj)
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
                test = -1;
            }
        }
    }

    //���W�X�V
    CalcObjPos();
    capsule->Update(objPos);
    line->Update(objPos);

    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));
}

void Player::Draw()
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

    DrawFormatString(0, 100, GetColor(255, 255, 255), "%d",test);

    DrawFormatString(1050, 0, GetColor(255, 255, 255), "���g���W%f,%f", capsule->GetWorldStartPos().x, capsule->GetWorldStartPos().z);
#endif // _DEBUG
}