#include<DxLib.h>
#include<memory>

#include"GameMgr/GameMgr.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    //�Q�[���V�[���Ǘ�
    GameMgr* gmMgr(new GameMgr);
    gmMgr->Procces();

    //�\�t�g�̏I��
    return 0;
}