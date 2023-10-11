#pragma once

#include"../AssetBase/AssetBase.h"

/// <summary>
/// Sound�N���X
/// </summary>
class Sound final:public AssetBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Sound();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Sound();


    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() override;
private:
    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void AddHandle(std::string fileName)override;

    /// <summary>
    /// �T�E���h�p�����[�^�[
    /// </summary>
    struct SoundParam
    {
        SoundParam();

        
        int volume;
    }soundParam;

    std::unordered_map<int, SoundParam> soundData;      //�T�E���h�f�[�^
};

