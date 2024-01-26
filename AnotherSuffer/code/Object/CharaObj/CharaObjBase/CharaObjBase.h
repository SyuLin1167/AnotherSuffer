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
        AxisData(std::string axis, CharaObjBase* obj, float rad = 0.0f);

        ~AxisData() {};

    private:

        void Rotate(const VECTOR& dir, const float& velocity);

        void RotateToAim(const VECTOR& dir,const float& velocity);
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
    
    AxisData* XAxisData;
    AxisData* YAxisData;
    AxisData* ZAxisData;

    bool isMove;                            //���씻��
    float moveSpeed;                        //�ړ����x

    static const float ROTATE_SPEED;        //��]���x
    bool nowRotate;                         //��]����
    MATRIX rotateXMat;                      //X����]�s��
    MATRIX rotateYMat;                      //Y����]�s��
    MATRIX rotateZMat;                      //Z����]�s��

    const rapidjson::Value& modelData;      //���f���p�X�f�[�^
    const rapidjson::Value& soundData;      //�T�E���h�p�X�f�[�^
    const rapidjson::Value& motionData;     //���[�V�����p�X�f�[�^

protected:
    VECTOR aimDir;                          //�ڕW���W
    float rotRad;                           //�p���x�̃��W�A���p
    float rotXRad;
    float rotYRad;                          //Y�����W�A���p
    float rotZRad;
    MATRIX rotYMat;                         //Y����]�s��
    MATRIX rotXMat;
    MATRIX rotZMat;
};

