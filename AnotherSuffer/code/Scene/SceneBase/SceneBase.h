#pragma once
#include<string>
#include"SceneTag.h"

/// <summary>
/// シーン基底クラス
/// </summary>
class SceneBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ</param>
    SceneBase(std::string tag);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~SceneBase();

    /// <summary>
    /// シーン更新
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    /// <returns>次フレームのシーン</returns>
    virtual SceneBase* UpdateScene(const float deltaTime) = 0;

    /// <summary>
    /// シーン描画
    /// </summary>
    virtual void DrawScene() = 0;

protected:
    std::string scaneTag;     //シーンのタグ
};

