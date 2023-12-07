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
    //視野にモデルがなかったら描画しない
    if (!CheckCameraViewClip_Box(VSub(objPos, VScale(objScale, CLIP_BOX_SIZE)),
        VAdd(objPos, VScale(objScale, CLIP_BOX_SIZE))))
    {
        isVisible = true;
    }
    else
    {
        isVisible = false;
    }

    //行列でモデルの動作
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

void Stage::Draw()
{
    //モデル描画
    MV1DrawModel(objHandle);
}