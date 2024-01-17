#include"../../ObjManager/ObjManager.h"
#include"../../../GameSystem/Window/Window.h"
#include "FirstPersonView.h"
#include"../../Math/Math.h"

static constexpr float LOOK_HEIGHT = 10.0f;    //���_����
static constexpr int PLAYER_HEAD_FRAME = 10;      //�v���C���[�����t���[��
static constexpr float MAX_PITCH = 1.0f;               //�s�b�`�ő�l

FirstPersonView::FirstPersonView()
    :ObjBase(ObjTag.CAMERA)
    , mousePosX(static_cast<int>(Window::GetWindowSize().x / 2))
    , mousePosY(static_cast<int>(Window::GetWindowSize().y / 2))
    , angleVel()
    , cameraYaw(-DX_PI_F / 2.0f)
    , cameraPitch(-DX_PI_F / 4.0f)
    , cameraViewMat(MGetIdent())
{
    SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);

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
    objWorldPos = VAdd(player->GetObjFramePos(PLAYER_HEAD_FRAME),objDir);

    //���_�ړ��Z�o
    CalcMoveView(deltaTime);
    objDir =  VGet(sinf(-cameraYaw), cameraPitch, cosf(-cameraYaw));
    cameraViewMat = MMult(MGetRotY(cameraYaw), MGetRotX(cameraPitch));

    //���_���J�������W���͂��ɓ�����
    objLocalPos = VNorm(objDir);
    objLocalPos.y=LOOK_HEIGHT;

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

    DrawCircle(objPos.z+60, objPos.x+60, 10, GetColor(255, 255, 255));
}