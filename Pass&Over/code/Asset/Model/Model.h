#pragma once
#include"../AssetBase/AssetBase.h"

/*Model�N���X*/
class Model final:public AssetBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Model();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Model();

    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void AddHandle(std::string fileName)override;

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() override;

private:
    int tmpHandle;                  //�ꎞ�ۑ��n���h��
    int dupHandle;                  //�����n���h��
};

