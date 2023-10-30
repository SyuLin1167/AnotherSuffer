#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// ���f���̃��[�V�����Ǘ�
/// </summary>
class Motion final:public AssetBase
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
    /// �f�[�^�ǉ�����
    /// </summary>
    /// <param name="key">:json�f�[�^�擾�L�[</param>
    void AddData(const rapidjson::Value& key);

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() override;

    /// <summary>
    /// ���[�V�����p�����[�^�[
    /// </summary>
    struct MotionParam
    {
    public:
        MotionParam();

        float playSpeed;            //�Đ����x
        bool isLoop;                //���[�v�Đ�����
        int index;                  //�C���f�b�N�X�ԍ�
        float totalTime;            //���Đ�����
    };

    int modelHandle;                                      //���f���n���h��
    int attachedIndex;                                    //�A�^�b�`��̃C���f�b�N�X

    std::unordered_map<int, MotionParam> motionData;      //���[�V�����f�[�^
};

