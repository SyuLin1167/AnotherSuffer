#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// ���f���̃��[�V�����Ǘ�
/// </summary>
class Motion:public AssetBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Motion();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Motion();

    /// <summary>
    /// ���[�V�����Đ�����
    /// </summary>
    /// <param name="handle">:�n���h��</param>
    void StartMotion(int handle);

    /// <summary>
    /// ���[�V������~����
    /// </summary>
    /// <param name="handle">:�n���h��</param>
    void StopMotion(int handle);

private:
    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void AddHandle(std::string fileName) override;

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() override;
};

