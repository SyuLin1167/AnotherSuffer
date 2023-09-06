#include "GameSetting.h"

// �R���X�g���N�^ //

GameSetting::GameSetting()
{
    BeforeLibInit();

    //���C�u����������
    if (DxLib_Init() < 0)
    {
        DebugBreak();
    }

    AfterLibInit();
}

// �f�X�g���N�^ //

GameSetting::~GameSetting()
{
    //���C�u�����I��
    DxLib_End();
}

// ���C�u�����������O���� //

void GameSetting::BeforeLibInit()
{
    //���O�̔�\��
    SetOutApplicationLogValidFlag(false);

    //�E�B���h�E�̐ݒ�
    ChangeWindowMode(true);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Pass&Over");

    //�A���`�G�C���A�X��ݒ�
    SetFullSceneAntiAliasingMode(4, 2);

    // Direct3D9Ex ���g�p����
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);
}

// ���C�u�����������㏈�� //

void GameSetting::AfterLibInit()
{
    //�`���𗠉�ʂɕύX
    SetDrawScreen(DX_SCREEN_BACK);

    //Z�o�b�t�@�ݒ�
    SetUseZBuffer3D(true);
    SetWriteZBuffer3D(true);
}