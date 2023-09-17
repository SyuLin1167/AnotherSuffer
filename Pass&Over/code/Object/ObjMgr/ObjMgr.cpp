#include<assert.h>

#include "ObjMgr.h"

std::unique_ptr<ObjMgr> ObjMgr::objMgr;

// �R���X�g���N�^ //

ObjMgr::ObjMgr()
    :object()
{
}

// �f�X�g���N�^ //

ObjMgr::~ObjMgr()
{
}

// �I�u�W�F�N�g�}�l�[�W���[���������� //

void ObjMgr::InitObjMgr()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!objMgr)
    {
        objMgr.reset(new ObjMgr);
    }
}

// �I�u�W�F�N�g�ǉ����� //

void ObjMgr::AddObj(ObjBase* newObj)
{
    ObjTag tag = newObj->GetTag();

    objMgr->object[tag].emplace_back(newObj);
}

// �I�u�W�F�N�g�X�V���� //

void ObjMgr::UpdateObj(const float deltaTime)
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
                DeleteObj(dead);
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
    auto iter = std::find(objMgr->object[tag].begin(), objMgr->object[tag].end(), unnecObj);
    assert(iter == objMgr->object[tag].end());

    //���������疖���Ɉړ������č폜
    if (iter != objMgr->object[tag].end())
    {
        std::iter_swap(iter, objMgr->object[tag].end() - 1);
        delete objMgr->object[tag].back();
        objMgr->object[tag].pop_back();
    }
}

// �S�I�u�W�F�N�g�폜���� //

void ObjMgr::DeleteAllObj()
{
    //�󂶂�Ȃ�������I�u�W�F�N�g�폜
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