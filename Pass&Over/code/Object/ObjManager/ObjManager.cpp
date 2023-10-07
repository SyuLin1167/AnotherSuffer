#include<assert.h>

#include "ObjManager.h"

std::unique_ptr<ObjManager> ObjManager::singleton;

// �R���X�g���N�^ //

ObjManager::ObjManager()
    :object()
{
}

// �f�X�g���N�^ //

ObjManager::~ObjManager()
{
}

// �I�u�W�F�N�g�}�l�[�W���[���������� //

void ObjManager::InitObjManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        singleton.reset(new ObjManager);
    }
}

// �I�u�W�F�N�g�ǉ����� //

void ObjManager::AddObj(ObjBase* newObj)
{
    ObjTag tag = newObj->GetTag();

    singleton->object[tag].emplace_back(newObj);
}

// �I�u�W�F�N�g�X�V���� //

void ObjManager::UpdateObj(const float deltaTime)
{
    //�S�^�O���X�V�������܂Ƃ߂čs��
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < singleton->object[tag].size(); i++)
        {
            singleton->object[tag][i]->Update(deltaTime);
        }
    }
}

// �I�u�W�F�N�g�`�揈�� //

void ObjManager::DrawObj()
{
    //�S�^�O���`�揈�����܂Ƃ߂čs��
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < singleton->object[tag].size(); i++)
        {
            //�I�u�W�F�N�g���������Ă�����`�悳����
            if (singleton->object[tag][i]->IsAlive())
            {
                singleton->object[tag][i]->Draw();
            }
        }
    }
}

// �I�u�W�F�N�g���S���� //

void ObjManager::OnDeadObj()
{
    //�S�^�O�����S�I�u�W�F�N�g��T���č폜
    for (auto& tag : objTagAll)
    {
        for (auto& dead: singleton->object[tag])
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

void ObjManager::DeleteObj(ObjBase* unnecObj)
{
    //�폜�I�u�W�F�N�g�̃^�O�擾
    ObjTag tag = unnecObj->GetTag();

    //�I�u�W�F�N�g������
    auto iter = std::find(singleton->object[tag].begin(), singleton->object[tag].end(), unnecObj);
    assert(iter == singleton->object[tag].end());

    //���������疖���Ɉړ������č폜
    if (iter != singleton->object[tag].end())
    {
        std::iter_swap(iter, singleton->object[tag].end() - 1);
        delete singleton->object[tag].back();
        singleton->object[tag].pop_back();
        singleton->object[tag].shrink_to_fit();
    }
}

// �S�I�u�W�F�N�g�폜���� //

void ObjManager::DeleteAllObj()
{
    //�󂶂�Ȃ�������I�u�W�F�N�g�폜
    for (auto& tag : objTagAll)
    {
        if (!singleton->object[tag].empty())
        {
            singleton->object[tag].clear();
            singleton->object[tag].shrink_to_fit();
        }
    }
}