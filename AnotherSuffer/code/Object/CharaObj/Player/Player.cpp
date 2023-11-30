#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
{
    //���f���ǂݍ���
    texHandle = LoadGraph("../assets/model/Chara/Player/PlayerFace.png");
    objHandle = model->GetHandle(modelData.GetString());
    objDir = VGet(0, 0, -1);
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

    motion->StartMotion(objHandle,
        motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));

    //�ړ����x�͑��鑬�x
    moveSpeed = RUN_SPEED;

    capsule = new Capsule(VAdd(objPos, VGet(0, 5, 0)),VAdd(objPos, VGet(0, 25, 0)), 5.0f);
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

    //���쒆
    if (isMove)
    {
        //�I�u�W�F�N�g�̍��W�Z�o
        CalcObjPos();

    }
    //��~��
    else
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

    MV1_COLL_RESULT_POLY_DIM colInfo = {};
    if (capsule->OnCollisionWithMesh(ObjManager::GetObj(ObjTag.STAGE)[0]->GetObjHandle(), colInfo))
    {
        a = 0;
        objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh(colInfo));
        objLocalPos.y = 0;
    }

        //�s��Ń��f���̓���
        MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

        capsule->Update(objPos);

        //��~���ɂ���
    isMove = false;
}

void Player::MoveChara(const float deltaTime)
{
    //�J�����̌��������g�̈ړ������Ƃ���
    std::shared_ptr<ObjBase> camera = ObjManager::GetObj(ObjTag.CAMERA)[0];
    VECTOR aimDir = camera->GetObjDir();
    VECTOR rightDir = VCross(VGet(0, -1, 0), aimDir);
    aimDir.y = 0;
    aimDir = VNorm(aimDir);

    //�L�[���͂ɂ��㉺���E�ړ�
    MoveByKey(KEY_INPUT_W, aimDir, deltaTime);
    MoveByKey(KEY_INPUT_S, VScale(aimDir, -1), deltaTime);
    MoveByKey(KEY_INPUT_A, rightDir, deltaTime);
    MoveByKey(KEY_INPUT_D, VScale(rightDir, -1), deltaTime);

    rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //�L�[�����͂���Ă�����ړ����̏������s
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        //�ړ��A�j���[�V�����Đ�
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //���W�E�����̎Z�o
        objLocalPos = VAdd(objLocalPos, VScale(dir, moveSpeed * deltaTime));

        //���쒆�ɂ���
        isMove = true;
    }
}

void Player::Draw()
{
    // �e�N�X�`���Ŏg�p����O���t�B�b�N�n���h����ύX����
    int texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    MV1SetTextureGraphHandle(objHandle, texIndex, texHandle, FALSE);

    //���f���`��
    MV1DrawModel(objHandle);

    DrawFormatString(0, 20, GetColor(255, 255, 255), "%f", a);
    DrawLine3D(objPos, VAdd(objPos, VScale(objDir,3)), GetColor(255, 0, 0));

    capsule->DrawDebug();
}