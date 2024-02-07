#pragma once

static constexpr float BLOCK_SIZE = 40.0f;                             //ブロックサイズ

static constexpr int WALL = 0x0001;                                    //壁
static constexpr int AISLE = 0x0002;                                   //通路
static constexpr int BARRICADE = 0x0004;                               //障壁

/// <summary>
/// ステージの管理
/// </summary>
class StageManager final
{
private:
    /// <summary>
    /// ブロックパラメーター
    /// </summary>
    struct BlockParam
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        BlockParam();

        int type;      //ブロックタイプ
        VECTOR pos;    //座標
    };

    std::unordered_map<int, std::unordered_map<int, BlockParam>> stageData;                //ステージデータ

public:
    /// <summary>
    /// ステージ管理初期化
    /// </summary>
    static void InitStageManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~StageManager();

    /// <summary>
    /// ステージデータ取得
    /// </summary>
    /// <returns>ステージデータ</returns>
    static std::unordered_map<int, std::unordered_map<int, BlockParam>> GetStageData() { return singleton->stageData; }

    /// <summary>
    /// 障壁の数取得
    /// </summary>
    /// <returns>障壁の数</returns>
    static const int GetBarricadeNum() { return singleton->barricadeNum; }

    /// <summary>
    /// 障壁のカウント
    /// </summary>
    static void CountBarricade() { singleton->barricadeNum--; }

    /// <summary>
    /// データ変更
    /// </summary>
    /// <param name="cell">:セル</param>
    /// <param name="type">:ブロックタイプ</param>
    static void ChangeStageData(std::pair<int,int> cell,int type);

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    StageManager();

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

    static std::unique_ptr<StageManager> singleton;     //自身の実体

    std::vector<int> dirArray;                          //ステージ生成用方向配列
    int barricadeNum;                                   //障壁の数
};

