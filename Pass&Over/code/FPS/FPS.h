#pragma once

/*FPS�N���X*/
class FPS
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    FPS();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~FPS();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update();

    /// <summary>
    /// �t���[�����[�g�擾����
    /// </summary>
    /// <returns>�t���[�����[�g</returns>
    float GetDeltaTime() const { return deltaTime; }

private:
    float nowTime;      //���݂̎���
    float prevTime;     //�ߋ��̎���
    float deltaTime;    //�t���[�����[�g
};

