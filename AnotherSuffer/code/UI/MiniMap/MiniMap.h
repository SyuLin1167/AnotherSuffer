#pragma once

/// <summary>
/// ミニマップ
/// </summary>
class MiniMap
{
public:
    /// <summary>
    /// ミニマップ初期化処理
    /// </summary>
    static void InitMiniMap();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~MiniMap();

    /// <summary>
    /// マップデータ追加処理
    /// </summary>
    /// <param name="pos">:座標</param>
    /// <param name="color">:色</param>
    static void AddMapData(VECTOR& pos,unsigned int& color);

    /// <summary>
    /// 更新
    /// </summary>
    static void Update();

    /// <summary>
    /// 描画
    /// </summary>
    static void Draw();

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    MiniMap();

    static std::unique_ptr<MiniMap> singleton;     //自身の実体

    std::vector<std::shared_ptr<ObjBase>> stage;
    ObjBase* player;

    bool isVisible;

    struct MiniMapData
    {
    public:
        MiniMapData();
        VECTOR pos;
        unsigned int color;
    };
    std::vector<MiniMapData> mapData;
};

