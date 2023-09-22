#pragma once

/*Model�N���X*/
class Model final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Model();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Model();

    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    void AddHandle();

    /// <summary>
    /// �n���h���擾����
    /// </summary>
    /// <param name="modelName">���f����</param>
    /// <returns>�n���h��</returns>
    int GetHandle(std::string modelName);

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    void DeleteHandle();

private:
    std::unordered_map<std::string, int> modelData;
    std::vector<int> modelHandle;
};

