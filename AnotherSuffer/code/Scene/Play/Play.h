#pragma once
#include<memory>

/// <summary>
/// プレイシーン
/// </summary>
class Play:public SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Play();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Play();

private:
    /// <summary>
    /// シーン更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    /// <returns>次フレームのシーン</returns>
    SceneBase* UpdateScene(const float deltaTime) override;

    /// <summary>
    /// シーン描画
    /// </summary>
    void DrawScene() override;
};

