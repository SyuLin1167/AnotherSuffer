#include<DxLib.h>
#include<memory>

#include"GameSystem/GameManager/GameManager.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    //ゲームシーン管理
    std::shared_ptr<GameManager> gameManager(new GameManager);
    gameManager->Procces();

    //ソフトの終了
    return 0;
}