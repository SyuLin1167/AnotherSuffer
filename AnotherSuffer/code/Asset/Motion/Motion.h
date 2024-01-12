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
    /// <param name="model">:���f���C���X�^���X</param>
    Motion(class Model* model);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Motion();

    /// <summary>
    /// ���[�V�������Ԍo��
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void AddMotionTime( const float deltaTime);

    /// <summary>
    /// ���[�V�����Đ�
    /// </summary>
    /// <param name="model">:���f���n���h��</param>
    /// <param name="handle">:�n���h��</param>
    void StartMotion(int model, int handle);

    /// <summary>
    /// ���[�V������~
    /// </summary>
    /// <param name="handle">:�n���h��</param>
    void StopMotion(int handle);

    /// <summary>
    /// �Đ�����
    /// </summary>
    /// <param name="handle">:�n���h��</param>
    /// <returns>�Đ���:true|��~��:false</returns>
    bool IsPlaying(int handle);

private:
    /// <summary>
    /// �n���h���ǉ�
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void AddHandle(std::string fileName) override;

    /// <summary>
    /// �f�[�^�ǉ�
    /// </summary>
    /// <param name="key">:json�f�[�^�擾�L�[</param>
    void AddData(const rapidjson::Value& key);

    /// <summary>
    /// �n���h���폜
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
        float nowMotionTime;        //���݂̃��[�V��������
        float totalTime;            //���Đ�����
    };

    int modelHandle;                                    //���f���n���h��


    std::unordered_map<int, MotionParam> motionData;    //���[�V�����f�[�^
    std::unordered_map<int, int> attachedIndex;         //�A�^�b�`��̃C���f�b�N�X�f�[�^
};

