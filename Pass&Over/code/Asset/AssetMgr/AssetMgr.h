#pragma once
#include<memory>

/*AssetMgr�N���X*/
class AssetMgr final
{
public:
    AssetMgr();
    ~AssetMgr();
    Model ModelInstance() { return *model; }

private:
    std::unique_ptr<class Model> model;
};

