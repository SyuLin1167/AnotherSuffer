#include<DxLib.h>
#include<assert.h>

#include "GameSetting.h"

std::unique_ptr<GameSetting> GameSetting::singleton = nullptr;

// ���������� //

void GameSetting::Init()
{
    if (!singleton)
    {
        singleton.reset(new GameSetting);
    }
}

// �R���X�g���N�^ //

GameSetting::GameSetting()
{
    BeforeLibInit();

    //���C�u����������
    assert(!DxLib_Init());

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