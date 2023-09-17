#pragma once
#include"../../ObjBase/ObjBase.h"

/*CharaObjBaseクラス*/
class CharaObjBase:public ObjBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CharaObjBase(ObjTag tag);

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


};

