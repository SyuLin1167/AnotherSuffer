#pragma once
#include<vector>
#include<unordered_map>

/// <summary>
/// ステージの管理
/// </summary>
class StageManager final
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    StageManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~StageManager();

private:
    /// <summary>
    /// ステージデータ初期化
    /// </summary>
    void InitStageData();

    /// <summary>
    /// ステージ生成
    /// </summary>
    /// <param name="indexX">横軸添え字番号</param>
    /// <param name="indexY">縦軸添え字番号</param>
    void CreateStage(int indexX = 1, int indexY = 1);

    /// <summary>
    /// 進行方向シャッフル
    /// </summary>
    void ShuffleDirection();

    /// <summary>
    /// 障壁ブロック変更判定
    /// </summary>
    /// <returns></returns>
    void ChangeToBarricade();

    /// <summary>
    /// デバッグ用描画
    /// </summary>
    void DebugDraw();

    const float BLOCK_SIZE = 40.0f;                             //ブロックサイズ
    const int STAGE_SIZE = 17;                                  //ステージサイズ

    const int UP = 0x0001;                                      //上
    const int DOWN = 0x0002;                                    //下
    const int LEFT = 0x0004;                                    //左
    const int RIGHT = 0x0008;                                   //右
    std::vector<int> dirArray = { UP, DOWN, LEFT, RIGHT };      //ステージ生成用方向配列

    const int WALL = 0x0001;                                    //壁
    const int AISLE = 0x0002;                                   //通路
    const int BARRICADE = 0x0004;                               //障壁
    std::unordered_map<int, std::vector<int>> stageData;        //ステージデータ
};

