#include "Astar.h"
#include"../../StageObj/StageManager/StageManager.h"

std::vector<std::pair<int, int>> Astar::Algorithm(const std::vector<std::vector<int>>& maze, std::pair<int, int> start, std::pair<int, int> goal)
{
    const int rows = StageManager::GetStageData().size();
    const int cols = StageManager::GetStageData()[0].size();

    std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>> openList(
        [](Node* a, Node* b)
        {
            return a->Evaluation() > b->Evaluation();  // 小さい方が優先
        });

    std::vector< std::vector<bool>> closed(rows, std::vector<bool>(cols, false));

    Node* startNode = new Node(start.first, start.second, 0, Heuristic(start.first, start.second, goal.first, goal.second), nullptr);
    openList.push(startNode);

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        if (current->nodePos.x == goal.first && current->nodePos.y == goal.second) {
            // ゴールに到達
            std::vector< std::pair<int, int>> path;
            while (current != nullptr) {
                path.emplace_back(current->nodePos.x, current->nodePos.y);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
            }

        closed[current->nodePos.x][current->nodePos.y] = true;

            // 上下左右の移動を考慮
        const std::vector< std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (const auto& dir : directions) {
            int newX = current->nodePos.x + dir.first;
            int newY = current->nodePos.y + dir.second;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                StageManager::GetStageData()[newX][newY].type == AISLE && !closed[newX][newY]) 
            {
                int newG = current->nodeCost + 1;
                int newH = Heuristic(newX, newY, goal.first, goal.second);
                Node* newNode = new Node(newX, newY, newG, newH, current);
                openList.push(newNode);
            }
        }
    }

    // ゴールに到達できない場合は空のパスを返す
    return {};
}

Astar::Node::Node(int x, int y, int cost, int dis, Node* parent)
    :nodePos(VGet(x,y,0))
    ,nodeCost(cost)
    ,nodeDistance(dis)
    ,parent(parent)
{
    //処理なし
}
