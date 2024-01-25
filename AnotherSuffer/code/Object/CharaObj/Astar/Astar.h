#pragma once
#include<DxLib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>

/// <summary>
/// A*�A���S���Y��
/// </summary>
class Astar final
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Astar();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Astar();

    /// <summary>
    /// �q���[���X�e�B�b�N
    /// </summary>
    /// <param name="x">:�m�[�h���Wx</param>
    /// <param name="y">:�m�[�h���Wy</param>
    /// <param name="goalX">:�ڕW���Wx</param>
    /// <param name="goalY">:�ڕW���Wy</param>
    /// <returns>�}���n�b�^������</returns>
    int Heuristic(int x, int y, int goalX, int goalY);

    /// <summary>
    /// A*�A���S���Y��
    /// </summary>
    /// <param name="start">:�J�n���W</param>
    /// <param name="goal">:�ڕW���W</param>
    /// <returns>�o�H���</returns>
    std::vector< std::pair<int, int>> Algorithm(std::pair<int, int> start,  std::pair<int, int> goal) ;

private:
    /// <summary>
    /// �m�[�h
    /// </summary>
    struct Node 
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        /// <param name="x">:���Wx</param>
        /// <param name="y">:���Wy</param>
        /// <param name="cost">:�R�X�g</param>
        /// <param name="dis">:����</param>
        /// <param name="parent">:�e�m�[�h</param>
        Node(int x, int y, int cost, int dis, Node* parent);

        VECTOR nodePos;        //�m�[�h���W
        int nodeCost;           //�R�X�g
        int nodeDistance;       //����
        Node* parent;          //�e�m�[�h

        int Evaluation() const { return nodeCost + nodeDistance; }  //�]���l
    };
};

