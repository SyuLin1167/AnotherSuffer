#pragma once
#include<memory>

/// <summary>
/// �}�E�X�|�C���^�[
/// </summary>
class MousePoint
{
public:
    /// <summary>
    /// �}�E�X�|�C���^�[����������
    /// </summary>
    static void InitMousePoint();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~MousePoint();

    /// <summary>
    /// ����
    /// </summary>
    static void CanVisible() { singleton->isVisible = true; }

    /// <summary>
    /// �s����
    /// </summary>
    static void UnVisible() { singleton->isVisible = false; }

    /// <summary>
    /// �`��
    /// </summary>
    static void Draw();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    MousePoint();

    static std::unique_ptr<MousePoint> singleton;       //���g�̎���
    bool isVisible;
    int mouseHandle;
};

