#pragma once
#include<DxLib.h>
#include<memory>

/*GameManager�N���X*/
class GameMgr final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GameMgr();

    /// <summary>
    /// ����
    /// </summary>
    void Procces();

private:
    std::unique_ptr<class GameSetting> gmSet;    //�Q�[���Z�b�e�B���O
    std::unique_ptr<class SceneMgr> sceneMgr;    //�V�[���}�l�[�W���[
};

