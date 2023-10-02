#pragma once
#include<memory>
#include<string.h>
#include<unordered_map>
#include<../Rapidjson/istreamwrapper.h>
#include<../Rapidjson/document.h>
#include<fstream>

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
    /// Json�t�@�C���ǂݍ��ݏ���
    /// </summary>
    /// <param name="fileName">�t�@�C����</param>
    void LoadJsonFile(std::string fileName);

    /// <summary>
    /// �n���h���L�[�擾����
    /// </summary>
    /// <returns>�t�@�C���f�[�^</returns>
    const rapidjson::Document GetHandleKey();

    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    virtual void AddHandle(std::string fileName) = 0;

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
    std::unordered_map < std::string, int > handle;     //�n���h��
    rapidjson::Value& data;                             //�t�@�C���f�[�^
    rapidjson::Document doc;                            //�h�L�������g
};

