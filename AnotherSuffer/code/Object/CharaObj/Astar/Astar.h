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
    struct Node 
    {
    public:
        Node(int x, int y, int cost, int dis, Node* parent);

        VECTOR nodePos;        //�m�[�h���W
        int nodeCost;           //�R�X�g
        int nodeDistance;       //����
        Node* parent;          //�e�m�[�h

        int Evaluation() const { return nodeCost + nodeDistance; }  //�]���l
    };

public:
    Astar() {};
    ~Astar() {};

    // �q���[���X�e�B�b�N�֐��i�}���n�b�^�������j
    int Heuristic(int x, int y, int goalX, int goalY) {
        return abs(x - goalX) + abs(y - goalY);
    }

    // A*�A���S���Y��
    std::vector< std::pair<int, int>> Algorithm(const  std::vector< std::vector<int>>& maze, std::pair<int, int> start,  std::pair<int, int> goal) ;
};

