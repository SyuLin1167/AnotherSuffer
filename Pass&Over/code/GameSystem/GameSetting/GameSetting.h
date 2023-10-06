#pragma once
#include<memory>

/*GameSetting�N���X*/
class GameSetting final
{
public:
    /// <summary>
    /// ����������
    /// </summary>
    static void Init();

    /// <summary>
    /// ���C�u�����������O����
    /// </summary>
    static void BeforeLibInit();

    /// <summary>
    /// ���C�u�����������㏈��
    /// </summary>
    static void AfterLibInit();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GameSetting();

private:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameSetting();

    static std::unique_ptr<GameSetting> singleton;     //���g�̎���
};

