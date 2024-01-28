#pragma once

/// <summary>
/// CharaObjBase�N���X
/// </summary>
class CharaObjBase :public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O��</param>
    CharaObjBase(std::string tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~CharaObjBase();

private:
    /// <summary>
    /// �A�Z�b�g�p�X�f�[�^�擾
    /// </summary>
    /// <param name="asset">:�C�ӂ̃A�Z�b�g</param>
    rapidjson::Value& GetAssetPathData(class AssetBase* asset);

    /// <summary>
    /// �����Ƃ̃f�[�^
    /// </summary>
    struct AxisData
    {
    public:
        /// <summary>
        /// �R���X�g���N�^ 
        /// </summary>
        /// <param name="axis">�F��</param>
        /// <param name="obj">:�I�u�W�F�N�g</param>
        /// <param name="rad">:�����p�x</param>
        AxisData(const std::string& axis, CharaObjBase* obj,const float rad = 0.0f);

        /// <summary>
        /// �f�X�g���N�^ 
        /// </summary>
        ~AxisData() {};

        /// <summary>
        /// ��]
        /// </summary>
        /// <param name="dir">:�ڕW����</param>
        /// <param name="velocity">:��]��</param>
        void Rotate(const VECTOR& dir, const float& velocity);

        /// <summary>
        /// �ڕW�����ւ̉�]
        /// </summary>
        /// <param name="dir">:�ڕW����</param>
        /// <param name="velocity">:��]��</param>
        void RotateToAim(const VECTOR& dir,const float& velocity);

        /// <summary>
        /// �ڕW�����ւ̒��ډ�]
        /// </summary>
        /// <param name="dir1">:�ڕW����</param>
        void RotateToAim(const VECTOR& dir);

        /// <summary>
        /// ��]�s��擾
        /// </summary>
        /// <returns></returns>
        MATRIX GetRotateMat()const { return rotMat; }
    private:
        /// <summary>
        /// ��]�����Z�o
        /// </summary>
        /// <param name="velocity">��]��</param>
        /// <returns>��]�������</returns>
        float CalcRotDir(const float& velocity);

        CharaObjBase* object;
        const std::string axisType;   //��
        VECTOR aimDir;              //�ڕW����
        float rotRad;           //��]�p
        float rotVel;           //��]��
        MATRIX rotMat;          //��]�s��
    };

    std::string xAxis = "xAxis";
    std::string yAxis = "yAxis";
    std::string zAxis = "zAxis";
protected:
    /// <summary>
    /// �L��������
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    virtual void MoveChara(const float deltaTime) = 0;
    
    std::unique_ptr<AxisData> XAxisData;
    std::unique_ptr<AxisData> YAxisData;
    std::unique_ptr<AxisData> ZAxisData;

    bool isMove;                            //���씻��
    float moveSpeed;                        //�ړ����x

    static const float ROTATE_SPEED;        //��]���x
    bool nowRotate;                         //��]����

    const rapidjson::Value& modelData;      //���f���p�X�f�[�^
    const rapidjson::Value& soundData;      //�T�E���h�p�X�f�[�^
    const rapidjson::Value& motionData;     //���[�V�����p�X�f�[�^
};

