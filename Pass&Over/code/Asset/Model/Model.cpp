#include<DxLib.h>

#include "Model.h"

// �R���X�g���N�^ //

Model::Model()
    :tmpHandle(-1)
    ,dupHandle(-1)
{
    
}

// �f�X�g���N�^ //

Model::~Model()
{

}

// �n���h���ǉ����� //

void Model::AddHandle(std::string fileName)
{
    //�n���h��������
    tmpHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto iter = handle.find(fileName);
    if (iter == handle.end())
    {
        tmpHandle = MV1LoadModel(fileName.c_str());
        dupHandle = MV1DuplicateModel(tmpHandle);
        handle.emplace(fileName, dupHandle);
    }
}

// �n���h���폜���� //

void Model::DeleteHandle()
{
    for (auto& iter : handle)
    {
        MV1DeleteModel(*iter.second);
        iter.second.reset();
    }
    handle.clear();
}