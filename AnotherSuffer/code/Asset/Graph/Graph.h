#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// �摜�Ǘ�
/// </summary>
class Graph final :public AssetBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Graph();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Graph();

private:
    /// <summary>
    /// �n���h���ǉ�
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void AddHandle(const std::string fileName) override;

    /// <summary>
    /// �n���h���폜
    /// </summary>
    void DeleteHandle() override;
};

