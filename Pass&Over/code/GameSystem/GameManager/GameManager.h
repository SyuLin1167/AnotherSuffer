#pragma once
#include<DxLib.h>
#include<memory>

/// <summary>
/// GameManager�N���X
/// </summary>
class GameManager final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameManager();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GameManager();

    /// <summary>
    /// ����
    /// </summary>
    void Procces();

private:
    std::unique_ptr<class SceneMgr> sceneMgr;    //�V�[���}�l�[�W���[
};

