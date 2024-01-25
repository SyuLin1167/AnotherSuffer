#pragma once
#include"../StageObjBase/StageObjBase.h"

/// <summary>
/// 障壁
/// </summary>
class Barricade final:public StageObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="pos">:座標</param>
    /// <param name="node">:ノード</param>
    Barricade(const VECTOR pos, std::pair<int, int> node);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Barricade();

    /// <summary>
    /// 当たり判定
    /// </summary>
    /// <param name="colObj">:判定するオブジェクト</param>
    void OnCollisionEnter(class ObjBase* colObj) override;

    /// <summary>
    /// 障壁破壊
    /// </summary>
    void BreakBarricade();

    std::pair<int, int> myNode;             //自身のノード
};

