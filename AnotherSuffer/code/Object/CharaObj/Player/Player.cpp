#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
    ,colInfo()
    ,moveVel()
{
    //���f���ǂݍ���
    objHandle = model->GetHandle(modelData.GetString());
    frameIdx = 0;
    objDir = VGet(0, 0, -1);
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

    motion->StartMotion(objHandle,
        motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));

    //�ړ����x�͑��鑬�x
    moveSpeed = RUN_SPEED*2;

    capsule=new Capsule(VAdd(objPos, VGet(0, 6, 0)), VAdd(objPos, VGet(0, 30, 0)), 6.0f);

    texHandle = CreatePointLightHandle(objPos, 150.0f, 0.0f, 0.0f, 0.001f);
}

Player::~Player()
{
    //�����Ȃ�
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    //�A�j���[�V�������ԍĐ�
    motion->AddMotionTime(deltaTime);

    //�L�����ړ�
    MoveChara(deltaTime);

    //��~��
    if(!isMove)
    {
        //�ʏ펞�A�j���[�V�����Đ�
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
    }

    //P�L�[�������ꂽ��
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, ONINPUT))
    {
        //���S�ɂ���
        isAlive = false;

        //�T�E���h�Đ�
        sound->StartSound(sound->GetHandle(GetFilePass(soundData[jsondata::objKey.walk.c_str()])));
    }

    if (KeyStatus::KeyStateDecision(KEY_INPUT_SPACE, ONINPUT))
    {
        frameIdx++;
    }

    //���W�X�V
    CalcObjPos();

    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Player::MoveChara(const float deltaTime)
{
    //��~���ɂ���
    isMove = false;

    //�J�����̌��������g�̈ړ������Ƃ���
    std::shared_ptr<ObjBase> camera = ObjManager::GetObj(ObjTag.CAMERA)[0];
    SetLightPositionHandle(texHandle, camera->GetObjPos());
    VECTOR aimDir = camera->GetObjDir();
    VECTOR rightDir = VCross(VGet(0, -1, 0), aimDir);
    aimDir.y = 0;
    aimDir = VNorm(aimDir);

    //�L�[���͂ɂ��ړ���
    moveVel = VGet(0, 0, 0);
    MoveByKey(KEY_INPUT_W, aimDir, deltaTime);
    MoveByKey(KEY_INPUT_S, VScale(aimDir, -1), deltaTime);
    MoveByKey(KEY_INPUT_A, rightDir, deltaTime);
    MoveByKey(KEY_INPUT_D, VScale(rightDir, -1), deltaTime);
    moveVel.y = 0;

    //���W�E�����̎Z�o
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));
    rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //�L�[�����͂���Ă�����ړ����̎��s
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel = VNorm(VAdd(moveVel, dir));

        //�ړ��A�j���[�V�����Đ�
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //���쒆�ɂ���
        isMove = true;
    }
}

void Player::OnCollisionEnter(ObjBase* colObj)
{
    if (capsule->OnCollisionWithMesh(colObj->GetObjHandle(), colInfo))
    {
        a = 0;
        objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh(colInfo));

        MV1CollResultPolyDimTerminate(colInfo);
    }

    //���W�X�V
    CalcObjPos();
    capsule->Update(objPos);

    //�s��Ń��f���̓���
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
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

    DrawFormatString(0, 20, GetColor(255, 255, 255), "%f", a);
    DrawLine3D(objPos, VAdd(objPos, VScale(objDir,3)), GetColor(255, 0, 0));

#endif // _DEBUG
}