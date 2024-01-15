#pragma once

static constexpr int WALL = 0x0001;                                    //��
static constexpr int AISLE = 0x0002;                                   //�ʘH
static constexpr int BARRICADE = 0x0004;                               //���

/// <summary>
/// �X�e�[�W�̊Ǘ�
/// </summary>
class StageManager final
{
private:
    /// <summary>
    /// �u���b�N�p�����[�^�[
    /// </summary>
    struct BlockParam
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        BlockParam();

        int type;      //�u���b�N�^�C�v
        VECTOR pos;    //���W
    };

public:
    /// <summary>
    /// �X�e�[�W�Ǘ�������
    /// </summary>
    static void InitStageManager();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~StageManager();

    /// <summary>
    /// �X�e�[�W�f�[�^�擾
    /// </summary>
    /// <returns>�X�e�[�W�f�[�^</returns>
    static std::unordered_map<int, std::unordered_map<int, BlockParam>> GetStageData() { return singleton->stageData; }

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    StageManager();

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

    static std::unique_ptr<StageManager> singleton;    //���g�̎���

    std::vector<int> dirArray;      //�X�e�[�W�����p�����z��
    std::unordered_map<int, std::unordered_map<int, BlockParam>> stageData;                //�X�e�[�W�f�[�^
};

