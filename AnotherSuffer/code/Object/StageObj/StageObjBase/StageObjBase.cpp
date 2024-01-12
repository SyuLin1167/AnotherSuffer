#include"../../ObjBase/ObjBase.h"
#include "StageObjBase.h"
#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Collision/CollisionManager/CollisionManager.h"
#include"../../../Collision/ColModel/ColModel.h"

static constexpr float CLIP_BOX_SIZE = 100.0f;     //�؂蔲���{�b�N�X�T�C�Y
static constexpr float CLIP_DISTANCE = 400.0f;     //�؂蔲������

StageObjBase::StageObjBase(const VECTOR pos)
    :ObjBase(ObjTag.STAGE)
    , graphData(AssetManager::GraphInstance()->GetJsonData()[objTag.c_str()])
    , clipBoxScale()
    , clipBoxPos1()
    , clipBoxPos2()
    , texHandle(-1)
    , texIndex()
{
    objHandle = MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
    AssetManager::ModelInstance()->GetJsonData()[objTag.c_str()].GetString()));
    MV1SetMeshBackCulling(objHandle, -1, true);
    MV1SetUseZBuffer(objHandle, true);
    objLocalPos = pos;

    objScale = VGet(0.2f, 0.3f, 0.2f);
    MV1SetScale(objHandle, objScale);

#ifdef _DEBUG
    MV1SetOpacityRate(objHandle, 0.3f);
#endif // _DEBUG

    //�s��Ń��f���̓���
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));

    //�����蔻��̓��f���^
    colModel.reset(new ColModel(objHandle));
    CollisionManager::AddCol(this, colModel.get());
}

StageObjBase::~StageObjBase()
{
    //�����Ȃ�
}

void StageObjBase::Update(const float deltaTime)
{
    //���f���؂蔲��
    ViewClipBox();

    //�s��Ń��f���̓���
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

void StageObjBase::ViewClipBox()
{
    //�v���C���[�����苗������Ă�����`�悵�Ȃ�
    player = ObjManager::GetObj(ObjTag.PLAYER)[0];
    VECTOR distance = VSub(objPos, player->GetObjPos());
    if (VSize(distance) > CLIP_DISTANCE)
    {
        isVisible = false;
        return;
    }

    //����ɃN���b�v�{�b�N�X���Ȃ�������`�悵�Ȃ�
    clipBoxScale = VScale(objScale, CLIP_BOX_SIZE);
    clipBoxPos1 = VSub(objPos, clipBoxScale);
    clipBoxPos2 = VAdd(objPos, VAdd(clipBoxScale, VGet(0, clipBoxScale.y, 0)));
    if (CheckCameraViewClip_Box(clipBoxPos1, clipBoxPos2))
    {
        isVisible = false;
        return;
    }

    //��{�͕`��
    isVisible = true;
}

void StageObjBase::Draw()
{
    //���f���`��
    MV1SetTextureGraphHandle(objHandle, texIndex, texHandle, true);
    MV1DrawModel(objHandle);
    DrawBox(objPos.z + 40, objPos.x + 40, objPos.z + 80, objPos.x + 80, GetColor(150, 100, 10), true);
}
