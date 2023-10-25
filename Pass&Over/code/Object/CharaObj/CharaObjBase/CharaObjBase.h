#pragma once
#include"../../ObjBase/ObjBase.h"

/// <summary>
/// CharaObjBaseクラス
/// </summary>
class CharaObjBase:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ名</param>
    CharaObjBase(std::string tag);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~CharaObjBase();

protected:
    /// <summary>
    /// キャラ動作処理
    /// </summary>
    /// <param name="deltaTime">:フレームレート</param>
    //virtual void MoveChara(const float deltaTime);

    /// <summary>
    /// キャラ回転処理
    /// </summary>
    //void RotateModel();
};

