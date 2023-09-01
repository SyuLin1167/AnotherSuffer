#include<DxLib.h>
#include<memory>

#include"GameMgr/GameMgr.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    //ゲームシーン管理
    std::shared_ptr<GameMgr> gmMgr(new GameMgr);
    gmMgr->Procces();
    gmMgr.~shared_ptr();

    //ソフトの終了
    return 0;
}