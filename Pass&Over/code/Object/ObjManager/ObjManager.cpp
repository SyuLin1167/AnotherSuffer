#include<assert.h>

#include "ObjManager.h"

std::shared_ptr<ObjManager> ObjManager::singleton;

// コンストラクタ //

ObjManager::ObjManager()
    :object()
{
    //処理なし
}

// デストラクタ //

ObjManager::~ObjManager()
{
    //処理なし
}

// オブジェクトマネージャー初期化処理 //

void ObjManager::InitObjManager()
{
    //自身の中身が空だったらインスタンス生成
    if (!singleton)
    {
        singleton.reset(new ObjManager);
    }
}

// オブジェクト追加処理 //

void ObjManager::AddObj(ObjBase* newObj)
{
    ObjTag tag = newObj->GetTag();

    singleton->object[tag].emplace_back(newObj);
}

// オブジェクト更新処理 //

void ObjManager::UpdateObj(const float deltaTime)
{
    //全タグ分更新処理をまとめて行う
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < singleton->object[tag].size(); i++)
        {
            singleton->object[tag][i]->Update(deltaTime);
        }
    }
    OnDeadObj();
}

// オブジェクト描画処理 //

void ObjManager::DrawObj()
{
    //全タグ分描画処理をまとめて行う
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < singleton->object[tag].size(); i++)
        {
            //オブジェクトが生存していたら描画させる
            if (singleton->object[tag][i]->IsVisible())
            {
                singleton->object[tag][i]->Draw();
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
        for (auto& dead: singleton->object[tag])
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

void ObjManager::DeleteObj(std::shared_ptr<ObjBase> unnecObj)
{
    //削除オブジェクトのタグ取得
    ObjTag tag = unnecObj->GetTag();

    //オブジェクトを検索
    auto endObj= singleton->object[tag].end();
    auto findObj = std::find(singleton->object[tag].begin(), endObj, unnecObj);
    assert(findObj != endObj);

    //見つかったら末尾に移動させて削除
    if (findObj != endObj)
    {
        std::swap(findObj, endObj);
        singleton->object[tag].pop_back();
        singleton->object[tag].shrink_to_fit();
    }
}

// 全オブジェクト削除処理 //

void ObjManager::DeleteAllObj()
{
    //空じゃなかったらオブジェクト削除
    for (auto& tag : objTagAll)
    {
        if (!singleton->object[tag].empty())
        {
            singleton->object[tag].clear();
            singleton->object[tag].shrink_to_fit();
        }
    }
}