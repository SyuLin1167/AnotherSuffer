#pragma once
#include"../CharaObjBase/CharaObjBase.h"

/// <summary>
/// 敵キャラ
/// </summary>
class Enemy final :public CharaObjBase
{
public:
    Enemy();
    ~Enemy();

private:
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="deltaTime">デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// キャラ動作
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void MoveChara(const float deltaTime) override;

    /// <summary>
    /// 視野外切り抜き
    /// </summary>
    void ViewClipBox();

    /// <summary>
    /// 当たり判定
    /// </summary>
    /// <param name="colObj">:判定するオブジェクト</param>
    void OnCollisionEnter(class ObjBase* colObj) override;

    /// <summary>
    /// ノードのリセット
    /// </summary>
    /// <param name="pos">:座標</param>
    /// <param name="node">:ノード</param>
    void ResetNode(VECTOR pos, std::pair<int, int>* node);

    /// <summary>
    /// 描画
    /// </summary>
    void Draw() override;

    VECTOR clipBoxScale;        //切り抜きボックススケール
    VECTOR clipBoxPos1;         //切り抜きボックス座標1
    VECTOR clipBoxPos2;         //切り抜きボックス座標2

    std::unique_ptr<class Astar> astar;
    std::vector<std::pair<int, int>> path;
    std::pair<int, int> start = {}, goal = {};
    float timer;

    ObjBase* player;            //プレイヤー
    class Line* line;
    class Capsule* capsule;
    VECTOR aimDir;
    bool isScream;
};