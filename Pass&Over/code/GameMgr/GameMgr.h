#pragma once

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
    class GameSetting* gmSet;       //�Q�[���Z�b�e�B���O
};

