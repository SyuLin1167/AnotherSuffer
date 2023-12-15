#pragma once
#include<vector>
#include<unordered_map>

/// <summary>
/// �X�e�[�W�̊Ǘ�
/// </summary>
class StageManager final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    StageManager();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~StageManager();

private:
    /// <summary>
    /// �X�e�[�W�f�[�^������
    /// </summary>
    void InitStageData();

    /// <summary>
    /// �X�e�[�W����
    /// </summary>
    /// <param name="indexX">�����Y�����ԍ�</param>
    /// <param name="indexY">�c���Y�����ԍ�</param>
    void CreateStage(int indexX = 1, int indexY = 1);

    /// <summary>
    /// �i�s�����V���b�t��
    /// </summary>
    void ShuffleDirection();

    /// <summary>
    /// ���ɐi�ރZ���Z�o
    /// </summary>
    /// <param name="dir">:�i�s����</param>
    /// <returns>���ɐi�ރZ���̈ʒu</returns>
    int CalcNextCell (int dir);

    /// <summary>
    /// �X�e�[�W���O����
    /// </summary>
    /// <param name="index">:���肷��Y�����ԍ�</param>
    /// <returns>�X�e�[�W��:true|�O:false</returns>
    bool IsOnStage(int index);

    /// <summary>
    /// ��ǃu���b�N�ݒu
    /// </summary>
    void SetBarricade();

    /// <summary>
    /// �I�u�W�F�N�g�z�u
    /// </summary>
    void PlacementObject();

    /// <summary>
    /// �f�o�b�O�p�`��
    /// </summary>
    //void DebugDraw();

    const float BLOCK_SIZE = 40.0f;                             //�u���b�N�T�C�Y
    const int STAGE_SIZE = 17;                                  //�X�e�[�W�T�C�Y
    const int MOVE_CELL = 1;                                    //�Z���̈ړ���
    const int TWO_CELL = 2;

    const int UP = 0x0001;                                      //��
    const int DOWN = 0x0002;                                    //��
    const int LEFT = 0x0004;                                    //��
    const int RIGHT = 0x0008;                                   //�E
    std::vector<int> dirArray = { UP, DOWN, LEFT, RIGHT };      //�X�e�[�W�����p�����z��

    const int WALL = 0x0001;                                    //��
    const int AISLE = 0x0002;                                   //�ʘH
    const int BARRICADE = 0x0004;                               //���
    std::unordered_map<int, std::vector<int>> stageData;        //�X�e�[�W�f�[�^
};

