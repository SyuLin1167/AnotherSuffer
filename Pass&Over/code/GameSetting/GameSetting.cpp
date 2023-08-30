#include "GameSetting.h"
#include<DxLib.h>

// �R���X�g���N�^ //

GameSetting::GameSetting()
{
    //���O�̔�\��
    SetOutApplicationLogValidFlag(false);

    //�E�B���h�E�̐ݒ�
    ChangeWindowMode(true);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, ColorBit);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Huhai");

    //�A���`�G�C���A�X��ݒ�
    SetFullSceneAntiAliasingMode(4, 2);

    // Direct3D9Ex ���g�p����
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);
}