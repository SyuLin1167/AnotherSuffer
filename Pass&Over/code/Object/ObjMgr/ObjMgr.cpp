#include<assert.h>

#include"../ObjBase/ObjBase.h"
#include"../ObjBase/ObjTag.h"
#include "ObjMgr.h"

std::shared_ptr<class ObjMgr> ObjMgr::objMgr = nullptr;

// オブジェクトマネージャー初期化処理 //

void ObjMgr::InitObjMgr()
{
    //自身の中身が空だったらインスタンス生成
    if (!objMgr.get())
    {
        objMgr = std::make_shared<class ObjMgr>(new ObjMgr);
    }
}

// オブジェクト追加処理 //

void ObjMgr::AddObj(ObjBase* newObj)
{
    objMgr->object.emplace(newObj->GetTag(), newObj);
}

// オブジェクト更新処理 //

void ObjMgr::UpdateObj(const float& deltaTime)
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
                DeleteObj(dead.get());
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
    auto iter = find(objMgr->object[tag].begin(),
        objMgr->object[tag].end(), unnecObj);
    assert(iter == objMgr->object[tag].end());

    //見つかったら末尾に移動させて削除
    if (iter != objMgr->object[tag].end())
    {
        std::iter_swap(iter, objMgr->object[tag].end() - 1);
        objMgr->object[tag].back().reset();
    }
}