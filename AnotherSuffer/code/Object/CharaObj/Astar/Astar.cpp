#include "Astar.h"
#include"../../StageObj/StageManager/StageManager.h"

static const std::vector< std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

Astar::Astar()
{
    //処理なし
}

Astar::~Astar()
{
    //処理なし
}

int Astar::Heuristic(int x, int y, int goalX, int goalY)
{
    return abs(x - goalX) + abs(y - goalY);
}

std::vector<std::pair<int, int>> Astar::Algorithm(std::pair<int, int> start, std::pair<int, int> goal)
{
    //ステージのサイズを行と列に分ける
    auto stage = StageManager::GetStageData();
    const int rows = stage.size();
    const int cols = stage[0].size();

    //評価が小さい順にまとめるリスト
    std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>> openList(
        [](Node* a, Node* b)
        {
            return a->Evaluation() > b->Evaluation();
        });

    //経路をすべて閉鎖
    std::vector< std::vector<bool>> closed(rows, std::vector<bool>(cols, false));

    //開始地点をリストに追加して探索開始
    Node* startNode = new Node(start.second, start.first, 0, Heuristic(start.first, start.second, goal.first, goal.second), nullptr);
    openList.push(startNode);

    //リストが空になるまで探索
    while (!openList.empty())
    {
        //リストの初めを現在のノードにする
        Node* current = openList.top();
        openList.pop();

        if (current->nodePos.x == goal.second && current->nodePos.y == goal.first)
        {
            // ゴールに到達したらパスにデータを追加
            std::vector< std::pair<int, int>> path;
            while (current != nullptr) {
                path.emplace_back(static_cast<int>(current->nodePos.x), static_cast<int>(current->nodePos.y));

                //現在のノードが持つ親ノードに切り替える
                current = current->parent;
            }

            //順番が逆なので戻して出来た経路を返す
            reverse(path.begin(), path.end());
            return path;
        }
        else
        {
            //*現在のノードの場所を解放
            closed[static_cast<int>(current->nodePos.x)][static_cast<int>(current->nodePos.y)] = true;

            // 上下左右次のマスを探索
            for (const auto& dir : directions)
            {
                int newX = static_cast<int>(current->nodePos.x) + dir.first;
                int newY = static_cast<int>(current->nodePos.y) + dir.second;

                //ステージ内にあったら一度探索した場所か確認
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols)
                {
                    if ((stage[newX][newY].type & AISLE) && !closed[newX][newY])
                    {
                        //未探索なら現在のノードを親として新規ノードをリストに追加
                        int newG = current->nodeCost + 1;
                        int newH = Heuristic(newX, newY, goal.first, goal.second);
                        Node* newNode = new Node(newX, newY, newG, newH, current);
                        openList.push(newNode);
                    }
                }
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
