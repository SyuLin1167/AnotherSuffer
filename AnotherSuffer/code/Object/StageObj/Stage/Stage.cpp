#include "Stage.h"

Stage::Stage()
    :ObjBase(ObjTag.STAGE)
{
    objHandle = model->GetHandle(model->GetJsonData()[objTag.c_str()].GetString());
    objLocalPos = VGet(30, 0, 20);

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
    //�s��Ń��f���̓���
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

void Stage::Draw()
{
    MV1DrawModel(objHandle);
}