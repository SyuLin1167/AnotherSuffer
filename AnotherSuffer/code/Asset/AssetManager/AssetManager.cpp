#include<DxLib.h>

#include "AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::singleton;

void AssetManager::InitAssetManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        SetUseASyncLoadFlag(true);
        singleton.reset(new AssetManager);
        SetUseASyncLoadFlag(false);
    }
}

AssetManager::AssetManager()
    :graph(new Graph)
    , model(new Model)
    , motion(new Motion(model.get()))
    , sound(new Sound)
{
    //�����Ȃ�
}

AssetManager::~AssetManager()
{
    //�����Ȃ�
}