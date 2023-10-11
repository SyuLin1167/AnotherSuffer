#include<assert.h>

#include "ObjManager.h"

std::unique_ptr<ObjManager> ObjManager::singleton;

/// <summary>
/// �R���X�g���N�^(�V���O���g��)
/// </summary>
ObjManager::ObjManager()
    :object()
{
    //�����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
ObjManager::~ObjManager()
{
    //�����Ȃ�
}

/// <summary>
/// �I�u�W�F�N�g�}�l�[�W���[����������
/// </summary>
void ObjManager::InitObjManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        singleton.reset(new ObjManager);
    }
}

/// <summary>
/// �I�u�W�F�N�g�ǉ�����
/// </summary>
/// <param name="newObj">:�ǉ��I�u�W�F�N�g</param>
void ObjManager::AddObj(ObjBase* newObj)
{
    ObjTag tag = newObj->GetTag();

    singleton->object[tag].emplace_back(newObj);
}

/// <summary>
/// �I�u�W�F�N�g�X�V����
/// </summary>
/// <param name="deltaTime">:�t���[�����[�g</param>
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
    OnDeadObj();
}

/// <summary>
/// �I�u�W�F�N�g�`�揈��
/// </summary>
void ObjManager::DrawObj()
{
    //�S�^�O���`�揈�����܂Ƃ߂čs��
    for (auto& tag : objTagAll)
    {
        for (int i = 0; i < singleton->object[tag].size(); i++)
        {
            //�I�u�W�F�N�g���������Ă�����`�悳����
            if (singleton->object[tag][i]->IsVisible())
            {
                singleton->object[tag][i]->Draw();
            }
        }
    }
}

/// <summary>
/// �I�u�W�F�N�g���S����
/// </summary>
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

/// <summary>
/// �I�u�W�F�N�g�폜����
/// </summary>
/// <param name="unnecObj">:�s�K�v�I�u�W�F�N�g</param>
void ObjManager::DeleteObj(std::shared_ptr<ObjBase> unnecObj)
{
    //�폜�I�u�W�F�N�g�̃^�O�擾
    ObjTag tag = unnecObj->GetTag();

    //�I�u�W�F�N�g������
    auto endObj= singleton->object[tag].end();
    auto findObj = std::find(singleton->object[tag].begin(), endObj, unnecObj);
    assert(findObj != endObj);

    //���������疖���Ɉړ������č폜
    if (findObj != endObj)
    {
        std::swap(findObj, endObj);
        singleton->object[tag].pop_back();
        singleton->object[tag].shrink_to_fit();
    }
}

/// <summary>
/// �S�I�u�W�F�N�g�폜����
/// </summary>
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