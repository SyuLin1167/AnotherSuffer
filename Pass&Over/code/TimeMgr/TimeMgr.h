#pragma once

/*TimeMgr�N���X*/
class TimeMgr
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    TimeMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~TimeMgr();

    /// <summary>
    /// �t���[�����[�g
    /// </summary>
    /// <returns>�t���[�����[�g</returns>
    const float DeltaTime();

private:
    float nowTime;      //���݂̎���
    float prevTime;     //�ߋ��̎���
    float deltaTime;    //�t���[�����[�g
};

