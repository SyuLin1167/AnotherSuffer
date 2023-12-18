#include"../../ObjManager/ObjManager.h"
#include"../../../GameSystem/Window/Window.h"
#include "FirstPersonView.h"
#include"../../Math/Math.h"

FirstPersonView::FirstPersonView()
    :ObjBase(ObjTag.CAMERA)
    , mousePosX(static_cast<int>(Window::GetWindowSize().x / 2))
    , mousePosY(static_cast<int>(Window::GetWindowSize().y / 2))
    , angleVel(VGet(0, 0, 0))
    , cameraYaw(-DX_PI_F / 2)
    , cameraPitch(-DX_PI_F / 4)
    , cameraViewMat(MGetIdent())
{
    SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);
    objLocalPos = ANGLE_POS;

    SetMousePoint(mousePosX, mousePosY);
    SetMouseDispFlag(false);
}

FirstPersonView::~FirstPersonView()
{
    //�����Ȃ�
}

void FirstPersonView::Update(const float deltaTime)
{
    //���W�擾
    player = ObjManager::GetObj(ObjTag.PLAYER)[0];
    assert(player);
    objWorldPos = player->GetObjFramePos();

    //���_�ړ��Z�o
    CalcMoveView(deltaTime);
    objDir =  VGet(sinf(-cameraYaw), cameraPitch, cosf(-cameraYaw));
    cameraViewMat = MMult(MGetRotY(cameraYaw), MGetRotX(cameraPitch));

    //�}�E�X�|�C���^�[�͉�ʂ̒��S
    SetMousePoint(static_cast<int>(Window::GetWindowSize().x / 2), static_cast<int>(Window::GetWindowSize().y / 2));

    //���W�X�V
    CalcObjPos();
}

void FirstPersonView::CalcMoveView(const float deltaTime)
{
    //�}�E�X�ړ���
    GetMousePoint(&mousePosX, &mousePosY);
    angleVel.x = static_cast<float>(mousePosX - Window::GetWindowSize().x / 2);
    angleVel.y = static_cast<float>(mousePosY - Window::GetWindowSize().y / 2);

    //�J������]�l�Z�o
    if (abs(angleVel.x) > 0)
    {
        cameraYaw -= angleVel.x * DX_PI_F * deltaTime/10;
    }
    if (abs(angleVel.y) > 0)
    {
        if (abs(cameraPitch) <= MAX_PITCH)
        {
            cameraPitch -= angleVel.y * DX_PI_F * deltaTime / 10;
        }
        else
        {
            //�s�b�`�̐���
            if (cameraPitch > MAX_PITCH)
            {
                cameraPitch = MAX_PITCH;
            }
            else
            {
                cameraPitch = -MAX_PITCH;
            }
        }
    }
}

void FirstPersonView::Draw()
{
    //���_���ړ�
    SetCameraViewMatrix(MMult( MInverse(MGetTranslate(objPos)),cameraViewMat));

    DrawFormatString(0, 300, GetColor(0, 255, 255), "%f", objDir.x);
    DrawFormatString(0, 350, GetColor(0, 255, 255), "%f", objDir.y);
    DrawFormatString(0, 400, GetColor(0, 255, 255), "%f", objDir.z);
}