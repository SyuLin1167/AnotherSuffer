#include "TitleCamera.h"
#include"../../../Object/ObjManager/ObjManager.h"
#include"../../Math/Math.h"

static constexpr int PLAYER_HEAD_FRAME = 10;      //�v���C���[�����t���[��

TitleCamera::TitleCamera()
    :ObjBase(ObjTag.CAMERA)
    ,rotAngle()
    ,rotRad()
{
    objWorldPos = VGet(-5, 0, -5);
    SetCameraNearFar(0.1f, 500.0f) ;
    //�����C�g
    handle = CreatePointLightHandle(objPos,  150.0f, 0.0f, 0.0001f, 0.0005f);
}

TitleCamera::~TitleCamera()
{
    DeleteLightHandle(handle);
}

void TitleCamera::Update(const float deltaTime)
{
    //�J�����𖳑���Ɉړ�
    rotAngle += deltaTime;
    rotRad = math::DegToRad(rotAngle);
    float moveX = cosf(rotAngle) - cosf(rotAngle) * sinf(rotAngle);
    float moveZ= sinf(rotAngle) - sinf(rotAngle) * cosf(rotAngle);
    objLocalPos = VAdd(objWorldPos, VGet(moveX * moveX, cosf(rotAngle) * sinf(rotAngle) + 50, moveZ * moveZ));

    //���W�X�V
    CalcObjPos();
    SetLightPositionHandle(handle, objPos);
}

void TitleCamera::Draw()
{
    SetCameraPositionAndTarget_UpVecY(objPos,VGet(50,10,20));
}