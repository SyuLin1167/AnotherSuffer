#pragma once
#include<memory>

/*AssetMgr�N���X*/
class AssetMgr final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    AssetMgr();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~AssetMgr();

    /// <summary>
    /// ���f���C���X�^���X
    /// </summary>
    /// <returns>Model�N���X</returns>
    Model ModelInstance() { return *model; }

private:
    std::unique_ptr<class Model> model;     //���f��
};

