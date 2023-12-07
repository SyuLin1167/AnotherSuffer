#include "Stage.h"

Stage::Stage(VECTOR pos)
    :ObjBase(ObjTag.STAGE)
{
    objHandle = MV1DuplicateModel(model->GetHandle(model->GetJsonData()[objTag.c_str()].GetString()));
    MV1SetMeshBackCulling(objHandle, -1, true);
    MV1SetUseZBuffer(objHandle, true);
    objLocalPos = pos;

    objScale = VGet(0.2f, 0.2f, 0.2f);
    MV1SetScale(objHandle, objScale);

#ifdef _DEBUG
    MV1SetOpacityRate(objHandle, 0.3f);
#endif // _DEBUG

    //�s��Ń��f���̓���
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

Stage::~Stage()
{
    //�����Ȃ�
}

void Stage::Update(const float deltaTime)
{
    //����Ƀ��f�����Ȃ�������`�悵�Ȃ�
    if (!CheckCameraViewClip_Box(VSub(objPos, VScale(objScale, CLIP_BOX_SIZE)),
        VAdd(objPos, VScale(objScale, CLIP_BOX_SIZE))))
    {
        isVisible = true;
    }
    else
    {
        isVisible = false;
    }

    //�s��Ń��f���̓���
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

void Stage::Draw()
{
    //���f���`��
    MV1DrawModel(objHandle);
}