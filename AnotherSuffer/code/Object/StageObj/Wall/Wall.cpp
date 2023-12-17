#include "Wall.h"

Wall::Wall(VECTOR pos)
    :ObjBase(ObjTag.STAGE)
{
    //texHandle = LoadGraph("");
    objHandle = MV1DuplicateModel(model->GetHandle(model->GetJsonData()[objTag.c_str()].GetString()));
    MV1SetMeshBackCulling(objHandle, -1, true);
    MV1SetUseZBuffer(objHandle, true);
    objLocalPos = pos;

    objScale = VGet(0.2f, 0.3f, 0.2f);
    MV1SetScale(objHandle, objScale);

#ifdef _DEBUG
    //MV1SetOpacityRate(objHandle, 0.3f);
#endif // _DEBUG

    //�s��Ń��f���̓���
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

Wall::~Wall()
{
    //�����Ȃ�
}

void Wall::Update(const float deltaTime)
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

void Wall::Draw()
{
    //// �e�N�X�`���Ŏg�p����O���t�B�b�N�n���h����ύX����
    //int texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    //MV1SetTextureGraphHandle(objHandle, texIndex, texHandle, FALSE);

    //���f���`��
    MV1DrawModel(objHandle);
    DrawBox(objPos.z+40, objPos.x+40, objPos.z + 80, objPos.x + 80, GetColor(150, 100, 10), true);
}