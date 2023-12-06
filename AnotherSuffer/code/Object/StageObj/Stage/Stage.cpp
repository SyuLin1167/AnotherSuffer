#include "Stage.h"

Stage::Stage(VECTOR pos)
    :ObjBase(ObjTag.STAGE)
{
    objHandle = MV1DuplicateModel(model->GetHandle(model->GetJsonData()[objTag.c_str()].GetString()));
    objLocalPos = pos;

    objScale = VGet(0.2f, 0.2f, 0.2f);
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
    if (!CheckCameraViewClip_Box(objPos, VAdd(objPos, VGet(40, 0, 40))) &&
        !CheckCameraViewClip_Box(objPos, VAdd(objPos, VGet(40, 40, 0)))&&
        !CheckCameraViewClip_Box(objPos, VAdd(objPos, VGet(0, 40, 40))))
    {
        MV1DrawModel(objHandle);
    }
}