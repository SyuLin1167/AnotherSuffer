#pragma once

/*TimeManager�N���X*/
class TimeManager
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    TimeManager();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~TimeManager();

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

