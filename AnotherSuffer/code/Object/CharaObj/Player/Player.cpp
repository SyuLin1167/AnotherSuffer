#include"../../../KeyStatus/KeyStatus.h"
#include"../../ObjManager/ObjManager.h"
#include"../../../Collision/Capsule/Capsule.h"
#include "Player.h"

Player::Player()
    :CharaObjBase(ObjTag.PLAYER)
{
    //モデル読み込み
    texHandle = LoadGraph("../assets/model/Chara/Player/PlayerFace.png");
    objHandle = model->GetHandle(modelData.GetString());
    objDir = VGet(0, 0, -1);
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));

    motion->StartMotion(objHandle,
        motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));

    //移動速度は走る速度
    moveSpeed = RUN_SPEED;

    capsule=new Capsule(VAdd(objPos, VGet(0, 5, 0)), VAdd(objPos, VGet(0, 25, 0)), 5.0f);
}

Player::~Player()
{
    colData.clear();
}

void Player::Update(const float deltaTime)
{
    a += deltaTime;
    //アニメーション時間再生
    motion->AddMotionTime(deltaTime);

    //キャラ移動
    MoveChara(deltaTime);

    //停止中
    if(!isMove)
    {
        //通常時アニメーション再生
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
    }

    //Pキーが押されたら
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, ONINPUT))
    {
        //死亡にする
        isAlive = false;

        //サウンド再生
        sound->StartSound(sound->GetHandle(GetFilePass(soundData[jsondata::objKey.walk.c_str()])));
    }

    //座標更新
    CalcObjPos();

    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Player::MoveChara(const float deltaTime)
{
    //停止中にする
    isMove = false;

    //カメラの向きを自身の移動方向とする
    std::shared_ptr<ObjBase> camera = ObjManager::GetObj(ObjTag.CAMERA)[0];
    VECTOR aimDir = camera->GetObjDir();
    VECTOR rightDir = VCross(VGet(0, -1, 0), aimDir);
    aimDir.y = 0;
    aimDir = VNorm(aimDir);

    //キー入力による移動量
    moveVel = VGet(0, 0, 0);
    MoveByKey(KEY_INPUT_W, aimDir, deltaTime);
    MoveByKey(KEY_INPUT_S, VScale(aimDir, -1), deltaTime);
    MoveByKey(KEY_INPUT_A, rightDir, deltaTime);
    MoveByKey(KEY_INPUT_D, VScale(rightDir, -1), deltaTime);

    //座標・方向の算出
    objLocalPos = VAdd(objLocalPos, VScale(moveVel, moveSpeed * deltaTime));
    rotateMat = MMult(MGetScale(objScale), MGetRotVec2(objDir, aimDir));
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //キーが入力されていたら移動時の処理実行
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        moveVel = VNorm(VAdd(moveVel, dir));

        //移動アニメーション再生
        motion->StartMotion(objHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //動作中にする
        isMove = true;
    }
}

void Player::OnCollisionEnter(ObjBase* colObj)
{
    auto findCol = colData.find(colObj);
    if (findCol == colData.end())
    {
        colData.emplace(colObj, colInfo);
    }

    if (capsule->OnCollisionWithMesh(colObj->GetObjHandle(), colData[colObj]))
    {
        a = 0;
        objLocalPos = VAdd(objLocalPos, capsule->CalcPushBackFromMesh(colData[colObj]));

        MV1CollResultPolyDimTerminate(colData[colObj]);
    }


    //座標更新
    CalcObjPos();
    capsule->Update(objPos);

    //行列でモデルの動作
    MV1SetMatrix(objHandle, MMult(rotateMat, MGetTranslate(objPos)));
}

void Player::Draw()
{
    // テクスチャで使用するグラフィックハンドルを変更する
    int texIndex = MV1GetMaterialDifMapTexture(objHandle, 0);
    MV1SetTextureGraphHandle(objHandle, texIndex, texHandle, FALSE);

    //モデル描画
    MV1DrawModel(objHandle);

#ifdef _DEBUG
    //当たり判定描画
    capsule->DrawCapsule();

    int hitnum = 0;
    for (auto& iter : colData)
    {
        // 当たったポリゴンの数だけ描画
        for (int i = 0; i < iter.second.HitNum; i++)
        {
            //当たったポリゴン
            DrawTriangle3D(
                iter.second.Dim[i].Position[0],
                iter.second.Dim[i].Position[1],
                iter.second.Dim[i].Position[2], GetColor(0, 255, 255), TRUE);


            //2辺から法線ベクトル算出
            VECTOR poligonVec1 = VSub(iter.second.Dim[i].Position[1], iter.second.Dim[i].Position[0]);
            VECTOR poligonVec2 = VSub(iter.second.Dim[i].Position[2], iter.second.Dim[i].Position[0]);
            VECTOR normalVec = VNorm(VCross(poligonVec1, poligonVec2));

            DrawLine3D(iter.second.Dim[i].Position[0], VAdd(iter.second.Dim[i].Position[0], normalVec), GetColor(255, 200, 0));
        }

        hitnum += iter.second.HitNum;
    }
        // 当たったポリゴンの数を描画
    DrawFormatString(0, 150, GetColor(255, 255, 255), "HitPolyNum %d", hitnum);

    DrawFormatString(0, 20, GetColor(255, 255, 255), "%f", a);
    DrawLine3D(objPos, VAdd(objPos, VScale(objDir,3)), GetColor(255, 0, 0));

#endif // _DEBUG
}