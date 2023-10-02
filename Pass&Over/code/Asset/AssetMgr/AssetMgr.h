#pragma once
#include<memory>

/*AssetMgr�N���X*/
class AssetMgr final
{
public:
    /// <summary>
    /// �A�Z�b�g�}�l�[�W���[����������
    /// </summary>
    static void InitAssetMgr();

    /// <summary>
    /// ���f���C���X�^���X
    /// </summary>
    /// <returns>Model�N���X</returns>
    static class Model* ModelInstance() { return assetMgr->model.get(); }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~AssetMgr();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    AssetMgr();

    static std::unique_ptr<AssetMgr> assetMgr;      //���g�̎���

    std::unique_ptr<class Model> model;             //���f��
};

