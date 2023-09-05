#include<DxLib.h>
#include<memory>

#include"GameMgr/GameMgr.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    //ゲームシーン管理
    GameMgr* gmMgr(new GameMgr);
    gmMgr->Procces();

    //ソフトの終了
    return 0;
}