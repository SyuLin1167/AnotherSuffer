#pragma once
#include<DxLib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>

/// <summary>
/// A*アルゴリズム
/// </summary>
class Astar final
{
    struct Node 
    {
    public:
        Node(int x, int y, int cost, int dis, Node* parent);

        VECTOR nodePos;        //ノード座標
        int nodeCost;           //コスト
        int nodeDistance;       //距離
        Node* parent;          //親ノード

        int Evaluation() const { return nodeCost + nodeDistance; }  //評価値
    };

public:
    Astar() {};
    ~Astar() {};

    // ヒューリスティック関数（マンハッタン距離）
    int Heuristic(int x, int y, int goalX, int goalY) {
        return abs(x - goalX) + abs(y - goalY);
    }

    // A*アルゴリズム
    std::vector< std::pair<int, int>> Algorithm(const  std::vector< std::vector<int>>& maze, std::pair<int, int> start,  std::pair<int, int> goal) ;
};

