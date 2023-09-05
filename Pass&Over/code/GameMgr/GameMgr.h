#pragma once
#include<DxLib.h>
#include<memory>

/*GameManagerクラス*/
class GameMgr final
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameMgr();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameMgr();

    /// <summary>
    /// 処理
    /// </summary>
    void Procces();

private:
    std::shared_ptr<class GameSetting> gmSet;    //ゲームセッティング
    std::shared_ptr<class SceneMgr> sceneMgr;    //シーンマネージャー
};

