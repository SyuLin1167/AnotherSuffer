#include "Wall.h"
#include"../../ObjManager/ObjManager.h"

static constexpr float CLIP_BOX_SIZE = 100.0f;     //切り抜きボックスサイズ
static constexpr float CLIP_DISTANCE = 400.0f;     //切り抜き距離

Wall::Wall(VECTOR pos)
    :ObjBase(ObjTag.STAGE)
    , clipBoxScale()
    , clipBoxPos1()
    , clipBoxPos2()
{
    // テクスチャで使用するグラフィックハンドルを変更する
    texHandle = LoadGraph("../assets/model/texture/Barricade.png");

    objHandle = MV1DuplicateModel(model->GetHandle(model->GetJsonData()[objTag.c_str()].GetString()));
    MV1SetMeshBackCulling(objHandle, -1, true);
    MV1SetUseZBuffer(objHandle, true);
    objLocalPos = pos;

    objScale = VGet(0.2f, 0.3f, 0.2f);
    MV1SetScale(objHandle, objScale);

#ifdef _DEBUG
    MV1SetOpacityRate(objHandle, 0.3f);
#endif // _DEBUG

    //行列でモデルの動作
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

Wall::~Wall()
{
    //処理なし
}

void Wall::Update(const float deltaTime)
{
    ViewClipBox();

    //行列でモデルの動作
    CalcObjPos();
    MV1SetMatrix(objHandle, MMult(MGetScale(objScale), MGetTranslate(objPos)));
}

void Wall::ViewClipBox()
{
    player = ObjManager::GetObj(ObjTag.PLAYER)[0];
    VECTOR distance = VSub(objPos, player->GetObjPos());
    if (VSize(distance) > CLIP_DISTANCE)
    {
        isVisible = false;
        return;
    }


    //視野にクリップボックスがなかったら描画しない
    clipBoxScale = VScale(objScale, CLIP_BOX_SIZE);
    clipBoxPos1 = VSub(objPos, clipBoxScale);
    clipBoxPos2 = VAdd(objPos, VAdd(clipBoxScale, VGet(0, clipBoxScale.y, 0)));
    if (CheckCameraViewClip_Box(clipBoxPos1, clipBoxPos2))
    {
        isVisible = false;
        return;
    }

    isVisible = true;
}

void Wall::Draw()
{
    //モデル描画
    texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    MV1SetTextureGraphHandle(objHandle, texIndex, texHandle, true);
    MV1DrawModel(objHandle);
    DrawBox(objPos.z+40, objPos.x+40, objPos.z + 80, objPos.x + 80, GetColor(150, 100, 10), true);
}