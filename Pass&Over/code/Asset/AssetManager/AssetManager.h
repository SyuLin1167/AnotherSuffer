#pragma once
#include<memory>

/// <summary>
/// AssetManager�N���X
/// </summary>
class AssetManager final
{
public:
    /// <summary>
    /// �A�Z�b�g�}�l�[�W���[����������
    /// </summary>
    static void InitAssetManager();

    /// <summary>
    /// ���f���C���X�^���X
    /// </summary>
    /// <returns>Model�N���X</returns>
    static class Model* ModelInstance() { return assetManager->model.get(); }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~AssetManager();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    AssetManager();

    static std::unique_ptr<AssetManager> assetManager;      //���g�̎���

    std::unique_ptr<class Model> model;             //���f��
};

