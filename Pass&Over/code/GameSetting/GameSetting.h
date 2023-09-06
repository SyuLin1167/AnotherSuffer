#pragma once
#include<DxLib.h>

constexpr int SCREEN_WIDTH = 1920;      //�X�N���[����
constexpr int SCREEN_HEIGHT = 1080;     //�X�N���[������


/*GameSetting�N���X*/
class GameSetting final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameSetting();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GameSetting();

    /// <summary>
    /// ���C�u�����������O����
    /// </summary>
    void BeforeLibInit();

    /// <summary>
    /// ���C�u�����������㏈��
    /// </summary>
    void AfterLibInit();

private:
    const int COLOR_BIT = 16;           //�J���[�r�b�g
};

