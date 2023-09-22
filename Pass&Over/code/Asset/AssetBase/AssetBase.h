#pragma once
#include<memory>
#include<string>
#include<unordered_map>
#include<../../IncludeFile/Rapidjson/istreamwrapper.h>
#include<../../IncludeFile/Rapidjson/document.h>

/*AssetBase�N���X*/
class AssetBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    AssetBase();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~AssetBase();

    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    virtual void AddHandle() = 0;

    /// <summary>
    /// �n���h���擾����
    /// </summary>
    /// <param name="handleName">�n���h����</param>
    /// <returns>�n���h��</returns>
    int GetHandle(std::string handleName);

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() = 0;

protected:
    std::unordered_map < std::string, std::unique_ptr<int> > handle;     //�n���h��
};

