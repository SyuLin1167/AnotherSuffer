#pragma once

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

    /// <summary>
    /// �f�o�b�O�p�`��
    /// </summary>
    void DebugDraw();

private:
    /// <summary>
    /// �X�e�[�W�f�[�^������
    /// </summary>
    void InitStageData();

    /// <summary>
    /// �X�e�[�W�쐬
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
    /// <param name="subDir">:����t���O</param>
    /// <param name="addDir">:����t���O</param>
    /// <returns>���ɐi�ރZ���̈ʒu</returns>
    int CalcNextCell(int dir, int subDir, int addDir);

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

    std::vector<int> dirArray;      //�X�e�[�W�����p�����z��

    std::unordered_map<int, std::unordered_map<int, int>> stageData;                //�X�e�[�W�f�[�^
};

