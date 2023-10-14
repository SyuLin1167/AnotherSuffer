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


private:
    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void AddHandle(std::string fileName) override ;

    /// <summary>
    /// �f�[�^�ǉ�����
    /// </summary>
    /// <param name="key">:json�f�[�^�擾�L�[</param>
    void AddData(const rapidjson::Value& key);

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() override;

    /// <summary>
    /// �T�E���h�p�����[�^�[
    /// </summary>
    struct SoundParam
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        SoundParam();

        std::string soundType;                          //�T�E���h�^�C�v
        bool isLoop;                                    //���[�v�Đ�����
        int volume;                                     //����
    };

    std::unordered_map<int, SoundParam> soundData;      //�T�E���h�f�[�^
};

