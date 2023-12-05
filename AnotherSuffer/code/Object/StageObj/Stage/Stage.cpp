#include "Stage.h"

Stage::Stage(VECTOR pos)
    :ObjBase(ObjTag.STAGE)
{
    objHandle = MV1DuplicateModel(model->GetHandle(model->GetJsonData()[objTag.c_str()].GetString()));
    objLocalPos = pos;

    objScale = VGet(0.1f, 0.1f, 0.1f);
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
    //�s��Ń��f���̓���
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

void Stage::Draw()
{
    MV1DrawModel(objHandle);
}