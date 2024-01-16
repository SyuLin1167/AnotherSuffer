#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// �G�L����
/// </summary>
class Enemy final :public CharaObjBase
{
public:
    Enemy();
    ~Enemy();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �L��������
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void MoveChara(const float deltaTime) override;

    /// <summary>
    /// �����蔻��
    /// </summary>
    /// <param name="colObj">:���肷��I�u�W�F�N�g</param>
    void OnCollisionEnter(class ObjBase* colObj) override;

    /// <summary>
    /// �m�[�h�̃��Z�b�g
    /// </summary>
    /// <param name="pos">:���W</param>
    /// <param name="node">:�m�[�h</param>
    void ResetNode(VECTOR pos, std::pair<int, int>* node);

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    class Astar* astar;
    std::vector<std::pair<int, int>> path;
    std::pair<int, int> start = {}, goal = {};
    float timer;
    
    std::shared_ptr<ObjBase> player;            //�v���C���[
    class Line* line;
    class Capsule* capsule;
};