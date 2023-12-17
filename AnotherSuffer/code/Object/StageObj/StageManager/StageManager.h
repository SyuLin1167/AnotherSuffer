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

    /// <summary>
    /// デバッグ用描画
    /// </summary>
    void DebugDraw();

private:
    /// <summary>
    /// ステージデータ初期化
    /// </summary>
    void InitStageData();

    /// <summary>
    /// ステージ作成
    /// </summary>
    /// <param name="indexX">横軸添え字番号</param>
    /// <param name="indexY">縦軸添え字番号</param>
    void CreateStage(int indexX = 1, int indexY = 1);

    /// <summary>
    /// 進行方向シャッフル
    /// </summary>
    void ShuffleDirection();

    /// <summary>
    /// 次に進むセル算出
    /// </summary>
    /// <param name="dir">:進行方向</param>
    /// <param name="subDir">:判定フラグ</param>
    /// <param name="addDir">:判定フラグ</param>
    /// <returns>次に進むセルの位置</returns>
    int CalcNextCell(int dir, int subDir, int addDir);

    /// <summary>
    /// ステージ内外判定
    /// </summary>
    /// <param name="index">:判定する添え字番号</param>
    /// <returns>ステージ内:true|外:false</returns>
    bool IsOnStage(int index);

    /// <summary>
    /// 障壁ブロック設置
    /// </summary>
    void SetBarricade();

    /// <summary>
    /// オブジェクト配置
    /// </summary>
    void PlacementObject();

    const float BLOCK_SIZE = 40.0f;                             //ブロックサイズ
    const int STAGE_SIZE = 17;                                  //ステージサイズ
    const int MOVE_CELL = 1;                                    //セルの移動量
    const int TWO_CELL = 2;

    const int UP = 0x0001;                                      //上
    const int DOWN = 0x0002;                                    //下
    const int LEFT = 0x0004;                                    //左
    const int RIGHT = 0x0008;                                   //右
    std::vector<int> dirArray = { UP, DOWN, LEFT, RIGHT };      //ステージ生成用方向配列

    const int WALL = 0x0001;                                    //壁
    const int AISLE = 0x0002;                                   //通路
    const int BARRICADE = 0x0004;                               //障壁
    std::unordered_map<int, 
        std::unordered_map<int, int>> stageData;                //ステージデータ
};

