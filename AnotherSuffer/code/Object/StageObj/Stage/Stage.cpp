#include "Stage.h"

Stage::Stage()
    :ObjBase(ObjTag.STAGE)
{
    objHandle = model->GetHandle(model->GetJsonData()[objTag.c_str()].GetString());
    objLocalPos = VGet(30, 0, 20);
}

Stage::~Stage()
{
    //ˆ—‚È‚µ
}

void Stage::Update(const float deltaTime)
{
    CalcObjPos();

    //s—ñ‚Åƒ‚ƒfƒ‹‚Ì“®ì
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

void Stage::Draw()
{
    MV1DrawModel(objHandle);
}