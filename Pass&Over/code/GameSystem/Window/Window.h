#pragma once
#include<memory>

constexpr int SCREEN_WIDTH = 1920;      //�X�N���[����
constexpr int SCREEN_HEIGHT = 1080;     //�X�N���[������

/*Window�N���X*/
class Window
{
public:
    /// <summary>
    /// ����������
    /// </summary>
    static void Init();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Window();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    Window();

    static std::unique_ptr<Window> singleton;      //���g�̎���
    const int COLOR_BIT = 16;           //�J���[�r�b�g
};

