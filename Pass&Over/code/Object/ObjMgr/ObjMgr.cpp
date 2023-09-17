#include<assert.h>

#include "ObjMgr.h"

std::unique_ptr<ObjMgr> ObjMgr::objMgr;

// コンストラクタ //

ObjMgr::ObjMgr()
    :object()
{
}

// デストラクタ //

ObjMgr::~ObjMgr()
{
}

// オブジェクトマネージャー初期化処理 //

void ObjMgr::InitObjMgr()
{
    //自身の中身が空だったらインスタンス生成
    if (!objMgr)
    {
        objMgr.reset(new ObjMgr);
    }
}

// オブジェクト追加処理 //

void ObjMgr::AddObj(ObjBase* newObj)
{
    ObjTag tag = newObj->GetTag();

    objMgr->object[tag].emplace_back(newObj);
}

// オブジェクト更新処理 //

void ObjMgr::UpdateObj(const float deltaTime)
{
    //全タグ分更新処理をまとめて行う
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < objMgr->object[tag].size(); i++)
        {
            objMgr->object[tag][i]->Update(deltaTime);
        }
    }
}

// オブジェクト描画処理 //

void ObjMgr::DrawObj()
{
    //全タグ分描画処理をまとめて行う
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < objMgr->object[tag].size(); i++)
        {
            //オブジェクトが生存していたら描画させる
            if (objMgr->object[tag][i]->IsAlive())
            {
                objMgr->object[tag][i]->Draw();
            }
        }
    }
}

// オブジェクト死亡処理 //

void ObjMgr::OnDeadObj()
{
    //全タグ分死亡オブジェクトを探して削除
    for (auto& tag : objTagAll)
    {
        for (auto& dead:objMgr->object[tag])
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

void ObjMgr::DeleteObj(ObjBase* unnecObj)
{
    //削除オブジェクトのタグ取得
    ObjTag tag = unnecObj->GetTag();

    //オブジェクトを検索
    auto iter = std::find(objMgr->object[tag].begin(), objMgr->object[tag].end(), unnecObj);
    assert(iter == objMgr->object[tag].end());

    //見つかったら末尾に移動させて削除
    if (iter != objMgr->object[tag].end())
    {
        std::iter_swap(iter, objMgr->object[tag].end() - 1);
        delete objMgr->object[tag].back();
        objMgr->object[tag].pop_back();
    }
}

// 全オブジェクト削除処理 //

void ObjMgr::DeleteAllObj()
{
    //空じゃなかったらオブジェクト削除
    for (auto& tag : objTagAll)
    {
        if (!objMgr->object[tag].empty())
        {
            objMgr->object[tag].clear();
            objMgr->object[tag].shrink_to_fit();
        }
    }

    objMgr->object.clear();
}