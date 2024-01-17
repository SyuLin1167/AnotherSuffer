#include<DxLib.h>
#include<assert.h>

#include "GameSetting.h"

std::unique_ptr<GameSetting> GameSetting::singleton = nullptr;

void GameSetting::InitGameSetting()
{
    if (!singleton)
    {
        singleton.reset(new GameSetting);
    }
}

GameSetting::GameSetting()
{
    BeforeLibInit();

    //ライブラリ初期化
    if (DxLib_Init() == -1)
    {
        DebugBreak();
    }

    AfterLibInit();
}

GameSetting::~GameSetting()
{
    //ライブラリ終了
    DxLib_End();
}

void GameSetting::BeforeLibInit()
{
    //アンチエイリアスを設定
    SetFullSceneAntiAliasingMode(4, 2);

    // Direct3D11 を使用する
    SetUseDirect3DVersion(DX_DIRECT3D_11);
}

void GameSetting::AfterLibInit()
{
    //描画先を裏画面に変更
    SetDrawScreen(DX_SCREEN_BACK);

    //Zバッファ設定
    SetUseZBuffer3D(true);
    SetWriteZBuffer3D(true);

    //標準ライトを無効化
    SetLightEnable(false);
    SetUsePixelLighting(true);
}