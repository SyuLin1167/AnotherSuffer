#include<DxLib.h>
//#include<stack>

#include"../SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include "SceneMgr.h"

// コンストラクタ //

SceneMgr::SceneMgr()
    :tmpScene(nullptr)
{
    nowScene.push(new Title);
}

// デストラクタ //

SceneMgr::~SceneMgr()
{
}

// ゲームループ //

void SceneMgr::GameLoop()
{
    //ウィンドウが閉じられるまでループする
    while (ProcessMessage() == 0)
    {

    }
}

// シーン更新処理 //

void SceneMgr::SceneUpdate()
{

}

// シーン描画処理 //

void SceneMgr::SceneDraw()
{

}