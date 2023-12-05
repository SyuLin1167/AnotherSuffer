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

    capsule = new Capsule(VAdd(objPos, VGet(0, 5, 0)), VAdd(objPos, VGet(0, 25, 0)), 5.0f);
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

    int i = 0;
    for (auto& iter : ObjManager::GetObj(ObjTag.STAGE))
    {
        colData.emplace_back(colInfo);

        if (capsule->OnCollisionWithMesh(iter->GetObjHandle(), colData[i]))
        {
            a = 0;
            objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh(colData[i],true));
            MV1CollResultPolyDimTerminate(colData[i]);
        }
        i++;
    }
        //�I�u�W�F�N�g�̍��W�Z�o
        CalcObjPos();

        capsule->Update(objPos);

        //�s��Ń��f���̓���
        MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));


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

    //�L�[���͂ɂ��ړ���
    moveVel = VGet(0, 0, 0);
    MoveByKey(KEY_INPUT_W, aimDir, deltaTime);
    MoveByKey(KEY_INPUT_S, VScale(aimDir, -1), deltaTime);
    MoveByKey(KEY_INPUT_A, rightDir, deltaTime);
    MoveByKey(KEY_INPUT_D, VScale(rightDir, -1), deltaTime);

    //���W�E�����̎Z�o
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));
    rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //�L�[�����͂���Ă�����ړ����̏������s
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

void Player::Draw()
{
    // �e�N�X�`���Ŏg�p����O���t�B�b�N�n���h����ύX����
    int texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    MV1SetTextureGraphHandle(objHandle, texIndex, texHandle, FALSE);

    //���f���`��
    MV1DrawModel(objHandle);

#ifdef _DEBUG
    //�����蔻��`��
    capsule->DrawCapsule();

    int hitnum = 0;
    for (auto& iter : colData)
    {
        // ���������|���S���̐������`��
        for (int i = 0; i < iter.HitNum; i++)
        {

            //���������|���S��
            DrawTriangle3D(
                iter.Dim[i].Position[0],
                iter.Dim[i].Position[1],
                iter.Dim[i].Position[2], GetColor(0, 255, 255), TRUE);

            //���������|���S���@��
            DrawLine3D(iter.Dim[i].Normal, VScale(iter.Dim[i].Normal, 3.0f), GetColor(255, 25, 255));
        }
        hitnum += iter.HitNum;
    }
        // ���������|���S���̐���`��
    DrawFormatString(0, 150, GetColor(255, 255, 255), "Hit Poly Num   %d", hitnum);

    DrawFormatString(0, 20, GetColor(255, 255, 255), "%f", a);
    DrawLine3D(objPos, VAdd(objPos, VScale(objDir,3)), GetColor(255, 0, 0));

#endif // _DEBUG
    colData.clear();
}