#include<DxLib.h>
#include<assert.h>

#include "GameSetting.h"

std::unique_ptr<GameSetting> GameSetting::singleton = nullptr;

/// <summary>
/// ����������
/// </summary>
void GameSetting::Init()
{
    if (!singleton)
    {
        singleton.reset(new GameSetting);
    }
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameSetting::GameSetting()
{
    BeforeLibInit();

    //���C�u����������
    assert(!DxLib_Init());

    AfterLibInit();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameSetting::~GameSetting()
{
    //���C�u�����I��
    DxLib_End();
}

/// <summary>
/// ���C�u�����������O����
/// </summary>
void GameSetting::BeforeLibInit()
{
    //�A���`�G�C���A�X��ݒ�
    SetFullSceneAntiAliasingMode(4, 2);

    // Direct3D9Ex ���g�p����
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);
}

/// <summary>
/// ���C�u�����������㏈��
/// </summary>
void GameSetting::AfterLibInit()
{
    //�`���𗠉�ʂɕύX
    SetDrawScreen(DX_SCREEN_BACK);

    //Z�o�b�t�@�ݒ�
    SetUseZBuffer3D(true);
    SetWriteZBuffer3D(true);
}