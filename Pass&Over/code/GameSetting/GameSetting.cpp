#include "GameSetting.h"

// コンストラクタ //

GameSetting::GameSetting()
{
    BeforeLibInit();

    //ライブラリ初期化
    if (DxLib_Init() < 0)
    {
        DebugBreak();
    }

    AfterLibInit();
}

// デストラクタ //

GameSetting::~GameSetting()
{
    //ライブラリ終了
    DxLib_End();
}

// ライブラリ初期化前処理 //

void GameSetting::BeforeLibInit()
{
    //ログの非表示
    SetOutApplicationLogValidFlag(false);

    //ウィンドウの設定
    ChangeWindowMode(true);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Pass&Over");

    //アンチエイリアスを設定
    SetFullSceneAntiAliasingMode(4, 2);

    // Direct3D9Ex を使用する
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);
}

// ライブラリ初期化後処理 //

void GameSetting::AfterLibInit()
{
    //描画先を裏画面に変更
    SetDrawScreen(DX_SCREEN_BACK);

    //Zバッファ設定
    SetUseZBuffer3D(true);
    SetWriteZBuffer3D(true);
}