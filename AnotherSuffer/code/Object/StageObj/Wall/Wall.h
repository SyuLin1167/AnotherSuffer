#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// �ǃu���b�N
/// </summary>
class Wall final:public ObjBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Wall(VECTOR pos);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Wall();

private:
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="deltaTime">�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �`��
    /// </summary>
    void Draw() override;

    const float CLIP_BOX_SIZE = 150.0f;
    int texHandle;
};

