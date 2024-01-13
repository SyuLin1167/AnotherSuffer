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

protected:
    /// <summary>
    /// �L��������
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    virtual void MoveChara(const float deltaTime) = 0;

    /// <summary>
    /// Y����]
    /// </summary>
    /// <param name="dir">:�ڕW�̌���</param>
    /// <param name="velocity">:�p���x</param>
    void RotateYAxis(const VECTOR dir, float velocity);

    /// <summary>
    /// ��]�����Z�o
    /// </summary>
    /// <returns>:</returns>
    /// <param name="velocity">:�p���x</param>
    float CalcRotDir(float velocity);

    bool isMove;                            //���씻��
    float moveSpeed;                        //�ړ����x

    static const float ROTATE_SPEED;        //��]���x
    bool nowRotate;                         //��]����
    MATRIX rotateMat;                       //��]�s��

    const rapidjson::Value& modelData;      //���f���p�X�f�[�^
    const rapidjson::Value& soundData;      //�T�E���h�p�X�f�[�^
    const rapidjson::Value& motionData;     //���[�V�����p�X�f�[�^

private:
    VECTOR aimDir;                          //�ڕW���W
    float rotRad;                           //�p���x�̃��W�A���p
    float rotYRad;                          //Y�����W�A���p
    MATRIX rotYMat;                         //Y����]�s��
};

