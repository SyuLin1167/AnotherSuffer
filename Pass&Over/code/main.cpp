#include<DxLib.h>
#include<memory>

#include"GameMgr/GameMgr.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    //�Q�[���V�[���Ǘ�
    std::shared_ptr<GameMgr> gmMgr(new GameMgr);
    gmMgr->Procces();
    gmMgr.~shared_ptr();

    //�\�t�g�̏I��
    return 0;
}