#include"../Model/Model.h"
#include "AssetMgr.h"

std::unique_ptr<AssetMgr> AssetMgr::assetMgr;

// �A�Z�b�g�}�l�[�W���[���������� //

void AssetMgr::InitAssetMgr()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!assetMgr)
    {
        assetMgr.reset(new AssetMgr);
    }
}

// �R���X�g���N�^ //

AssetMgr::AssetMgr()
{
    model.reset(new Model);
}

// �f�X�g���N�^ //

AssetMgr::~AssetMgr()
{

}