#include<assert.h>

#include"../ObjBase/ObjBase.h"
#include"../ObjBase/ObjTag.h"
#include "ObjMgr.h"

std::shared_ptr<class ObjMgr> ObjMgr::objMgr = nullptr;

// �I�u�W�F�N�g�}�l�[�W���[���������� //

void ObjMgr::InitObjMgr()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!objMgr.get())
    {
        objMgr = std::make_shared<class ObjMgr>(new ObjMgr);
    }
}

// �I�u�W�F�N�g�ǉ����� //

void ObjMgr::AddObj(ObjBase* newObj)
{
    objMgr->object.emplace(newObj->GetTag(), newObj);
}

// �I�u�W�F�N�g�X�V���� //

void ObjMgr::UpdateObj(const float& deltaTime)
{
    //�S�^�O���X�V�������܂Ƃ߂čs��
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < objMgr->object[tag].size(); i++)
        {
            objMgr->object[tag][i]->Update(deltaTime);
        }
    }
}

// �I�u�W�F�N�g�`�揈�� //

void ObjMgr::DrawObj()
{
    //�S�^�O���`�揈�����܂Ƃ߂čs��
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < objMgr->object[tag].size(); i++)
        {
            //�I�u�W�F�N�g���������Ă�����`�悳����
            if (objMgr->object[tag][i]->IsAlive())
            {
                objMgr->object[tag][i]->Draw();
            }
        }
    }
}

// �I�u�W�F�N�g���S���� //

void ObjMgr::OnDeadObj()
{
    //�S�^�O�����S�I�u�W�F�N�g��T���č폜
    for (auto& tag : objTagAll)
    {
        for (auto& dead:objMgr->object[tag])
        {
            //����ł�����I�u�W�F�N�g�폜
            if (!dead->IsAlive())
            {
                DeleteObj(dead.get());
            }
        }
    }
}

// �I�u�W�F�N�g�폜���� //

void ObjMgr::DeleteObj(ObjBase* unnecObj)
{
    //�폜�I�u�W�F�N�g�̃^�O�擾
    ObjTag tag = unnecObj->GetTag();

    //�I�u�W�F�N�g������
    auto iter = find(objMgr->object[tag].begin(),
        objMgr->object[tag].end(), unnecObj);
    assert(iter == objMgr->object[tag].end());

    //���������疖���Ɉړ������č폜
    if (iter != objMgr->object[tag].end())
    {
        std::iter_swap(iter, objMgr->object[tag].end() - 1);
        objMgr->object[tag].back().reset();
    }
}