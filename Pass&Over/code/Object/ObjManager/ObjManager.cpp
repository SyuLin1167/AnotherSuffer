#include<assert.h>

#include "ObjManager.h"

std::unique_ptr<ObjManager> ObjManager::objManager;

// コンストラクタ //

ObjManager::ObjManager()
    :object()
{
}

// デストラクタ //

ObjManager::~ObjManager()
{
}

// オブジェクトマネージャー初期化処理 //

void ObjManager::InitObjManager()
{
    //自身の中身が空だったらインスタンス生成
    if (!objManager)
    {
        objManager.reset(new ObjManager);
    }
}

// オブジェクト追加処理 //

void ObjManager::AddObj(ObjBase* newObj)
{
    ObjTag tag = newObj->GetTag();

    objManager->object[tag].emplace_back(newObj);
}

// オブジェクト更新処理 //

void ObjManager::UpdateObj(const float deltaTime)
{
    //全タグ分更新処理をまとめて行う
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < objManager->object[tag].size(); i++)
        {
            objManager->object[tag][i]->Update(deltaTime);
        }
    }
}

// オブジェクト描画処理 //

void ObjManager::DrawObj()
{
    //全タグ分描画処理をまとめて行う
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < objManager->object[tag].size(); i++)
        {
            //オブジェクトが生存していたら描画させる
            if (objManager->object[tag][i]->IsAlive())
            {
                objManager->object[tag][i]->Draw();
            }
        }
    }
}

// オブジェクト死亡処理 //

void ObjManager::OnDeadObj()
{
    //全タグ分死亡オブジェクトを探して削除
    for (auto& tag : objTagAll)
    {
        for (auto& dead:objManager->object[tag])
        {
            //死んでいたらオブジェクト削除
            if (!dead->IsAlive())
            {
                DeleteObj(dead);
            }
        }
    }
}

// オブジェクト削除処理 //

void ObjManager::DeleteObj(ObjBase* unnecObj)
{
    //削除オブジェクトのタグ取得
    ObjTag tag = unnecObj->GetTag();

    //オブジェクトを検索
    auto iter = std::find(objManager->object[tag].begin(), objManager->object[tag].end(), unnecObj);
    assert(iter == objManager->object[tag].end());

    //見つかったら末尾に移動させて削除
    if (iter != objManager->object[tag].end())
    {
        std::iter_swap(iter, objManager->object[tag].end() - 1);
        delete objManager->object[tag].back();
        objManager->object[tag].pop_back();
        objManager->object[tag].shrink_to_fit();
    }
}

// 全オブジェクト削除処理 //

void ObjManager::DeleteAllObj()
{
    //空じゃなかったらオブジェクト削除
    for (auto& tag : objTagAll)
    {
        if (!objManager->object[tag].empty())
        {
            objManager->object[tag].clear();
            objManager->object[tag].shrink_to_fit();
        }
    }
}