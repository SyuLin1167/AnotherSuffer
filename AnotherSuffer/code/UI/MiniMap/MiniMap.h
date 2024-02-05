#pragma once

/// <summary>
/// �~�j�}�b�v
/// </summary>
class MiniMap
{
public:
    /// <summary>
    /// �~�j�}�b�v����������
    /// </summary>
    static void InitMiniMap();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~MiniMap();

    /// <summary>
    /// �}�b�v�f�[�^�ǉ�����
    /// </summary>
    /// <param name="pos">:���W</param>
    /// <param name="color">:�F</param>
    static void AddMapData(VECTOR& pos,unsigned int& color);

    /// <summary>
    /// �X�V
    /// </summary>
    static void Update();

    /// <summary>
    /// �`��
    /// </summary>
    static void Draw();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    MiniMap();

    static std::unique_ptr<MiniMap> singleton;     //���g�̎���

    std::vector<std::shared_ptr<ObjBase>> stage;
    ObjBase* player;

    bool isVisible;

    struct MiniMapData
    {
    public:
        MiniMapData();
        VECTOR pos;
        unsigned int color;
    };
    std::vector<MiniMapData> mapData;
};

