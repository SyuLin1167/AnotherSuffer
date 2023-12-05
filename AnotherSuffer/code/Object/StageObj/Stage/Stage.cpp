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

    //行列でモデルの動作
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

Stage::~Stage()
{
    //処理なし
}

void Stage::Update(const float deltaTime)
{
    //行列でモデルの動作
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

void Stage::Draw()
{
    MV1DrawModel(objHandle);
}