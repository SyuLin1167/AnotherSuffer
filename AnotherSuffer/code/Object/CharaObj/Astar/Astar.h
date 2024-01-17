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
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Astar();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Astar();

    /// <summary>
    /// ヒューリスティック
    /// </summary>
    /// <param name="x">:ノード座標x</param>
    /// <param name="y">:ノード座標y</param>
    /// <param name="goalX">:目標座標x</param>
    /// <param name="goalY">:目標座標y</param>
    /// <returns>マンハッタン距離</returns>
    int Heuristic(int x, int y, int goalX, int goalY);

    /// <summary>
    /// A*アルゴリズム
    /// </summary>
    /// <param name="start">:開始座標</param>
    /// <param name="goal">:目標座標</param>
    /// <returns>経路情報</returns>
    std::vector< std::pair<int, int>> Algorithm(std::pair<int, int> start,  std::pair<int, int> goal) ;

private:
    /// <summary>
    /// ノード
    /// </summary>
    struct Node 
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="x">:座標x</param>
        /// <param name="y">:座標y</param>
        /// <param name="cost">:コスト</param>
        /// <param name="dis">:距離</param>
        /// <param name="parent">:親ノード</param>
        Node(int x, int y, int cost, int dis, Node* parent);

        VECTOR nodePos;        //ノード座標
        int nodeCost;           //コスト
        int nodeDistance;       //距離
        Node* parent;          //親ノード

        int Evaluation() const { return nodeCost + nodeDistance; }  //評価値
    };
};

