#include "GameSetting.h"
#include<DxLib.h>

// コンストラクタ //

GameSetting::GameSetting()
{
    //ログの非表示
    SetOutApplicationLogValidFlag(false);

    //ウィンドウの設定
    ChangeWindowMode(true);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, ColorBit);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Huhai");

    //アンチエイリアスを設定
    SetFullSceneAntiAliasingMode(4, 2);

    // Direct3D9Ex を使用する
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);
}