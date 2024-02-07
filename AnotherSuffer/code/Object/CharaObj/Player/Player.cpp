#include"../../../KeyStatus/KeyStatus.h"
#include"../../Math/Math.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Asset/AssetManager/AssetManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "Player.h"
#include"../../../UI/PhysicalMeter/PhysicalMeter.h"

static constexpr float WALK_SPEED = 40.0f;
static constexpr float RUN_SPEED = 80.0f;
static constexpr float SNIKE_SPEED = 20.0f;
static constexpr float PHYSICAL_SPEED = MAX_PARAM / 4;
static constexpr float CAPSULE_RAD = 8.0f;

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
    , moveVel()
    , physical()
    , canRunning(true)
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
    moveSpeed = WALK_SPEED;

    //�����蔻��̓J�v�Z���^
    capsule = new Capsule(VAdd(objWorldPos, VGet(0, 7, 0)), VAdd(objWorldPos, VGet(0, 30, 0)), CAPSULE_RAD);
    capsule->Update(objPos);
    CollisionManager::AddCol(this, capsule);

    //�����C�g
    texHandle = CreateSpotLightHandle(objPos,objDir,DX_PI_F/2,DX_PI_F/4, 150.0f, 0.0f, 0.0f, 0.0005f);
    test = 0;

    camera = ObjManager::GetObj(ObjTag.CAMERA, 0);
}

Player::~Player()
{
    DeleteLightHandle(texHandle);
}

void Player::Update(const float deltaTime)
{
    //�A�j���[�V�������ԍĐ�
    AssetManager::MotionInstance()->AddMotionTime(this, deltaTime);

    //�L�����ړ�
    if (KeyStatus::KeyStateDecision(KEY_INPUT_SPACE, (ONINPUT | NOWONINPUT)))
    {
        moveSpeed = SNIKE_SPEED;
    }
    else if (KeyStatus::KeyStateDecision(KEY_INPUT_LSHIFT, (ONINPUT | NOWONINPUT)))
    {
        if (isMove && canRunning)
        {
            moveSpeed = RUN_SPEED;
            if (physical <= MAX_PARAM)
            {
                physical += PHYSICAL_SPEED * deltaTime;
            }
            else
            {
                canRunning = false;
                moveSpeed = WALK_SPEED;
                physical = MAX_PARAM;
            }
        }
    }
    else
    {
        moveSpeed = WALK_SPEED;
    }

    if (!KeyStatus::KeyStateDecision(KEY_INPUT_LSHIFT, (ONINPUT | NOWONINPUT))||!canRunning)
    {
        if (physical > 0)
        {
            physical -= PHYSICAL_SPEED / 2 * deltaTime;
        }
        else
        {
            canRunning = true;
            physical = 0;
        }
    }
    PhysicalMeter::ChangePhysicalParam(physical);

    MoveChara(deltaTime);

    //��~��
    if (!isMove)
    {
        //�ʏ펞�A�j���[�V�����Đ�
        AssetManager::MotionInstance()->StartMotion(this,
            AssetManager::MotionInstance()->GetHandle(
                AssetManager::GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
    }

    //���W�X�V
    CalcObjPos();
    
    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(MMult(MGetScale(objScale), YAxisData->GetRotateMat()), MGetTranslate(objPos)));
}

void Player::MoveChara(const float deltaTime)
{
    if (isVisible)
    {
        //��~���ɂ���
        isMove = false;

        //�J�����̌����Ƀ��C�g���Ƃ炷
        SetLightDirectionHandle(texHandle, camera->GetObjDir());
        SetLightPositionHandle(texHandle, camera->GetObjPos());

        //�J�����̌��������g�̈ړ������Ƃ���
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
    else
    {
        DeleteLightHandle(texHandle);
    }
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //�L�[�����͂���Ă�����ړ����̎��s
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel = VNorm(VAdd(moveVel, dir));

        //�ړ��A�j���[�V�����Đ�
        if (moveSpeed == RUN_SPEED)
        {
            AssetManager::MotionInstance()->StartMotion(this,
                AssetManager::MotionInstance()->GetHandle(
                    AssetManager::GetFilePass(motionData[jsondata::objKey.run.c_str()])));
        }
        else
        {
            AssetManager::MotionInstance()->StartMotion(this,
                AssetManager::MotionInstance()->GetHandle(
                    AssetManager::GetFilePass(motionData[jsondata::objKey.walk.c_str()])));
        }

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
            continue;
        }
        if (obj->GetColTag() == ColTag.CAPSULE)
        {
            if (capsule->OnCollisionWithCapsule(obj->GetWorldStartPos(), obj->GetWorldEndPos(), obj->GetRadius() * 2.6f))
            {
                isVisible = false;
                return;
            }
        }
    }

    //���W�X�V
    CalcObjPos();
    capsule->Update(objPos);

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