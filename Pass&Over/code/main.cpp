#include<DxLib.h>
#include<memory>

#include"GameSystem/GameManager/GameManager.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    //�Q�[���V�[���Ǘ�
    std::unique_ptr<GameManager> gmMgr(new GameManager);
    gmMgr->Procces();
    gmMgr.reset();

    //�\�t�g�̏I��
    return 0;
}