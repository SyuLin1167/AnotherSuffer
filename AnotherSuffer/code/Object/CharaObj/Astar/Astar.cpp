#include "Astar.h"
#include"../../StageObj/StageManager/StageManager.h"

static const std::vector< std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

Astar::Astar()
{
    //�����Ȃ�
}

Astar::~Astar()
{
    //�����Ȃ�
}

int Astar::Heuristic(int x, int y, int goalX, int goalY)
{
    return abs(x - goalX) + abs(y - goalY);
}

std::vector<std::pair<int, int>> Astar::Algorithm(std::pair<int, int> start, std::pair<int, int> goal)
{
    //�X�e�[�W�̃T�C�Y���s�Ɨ�ɕ�����
    auto stage = StageManager::GetStageData();
    const int rows = stage.size();
    const int cols = stage[0].size();

    //�]�������������ɂ܂Ƃ߂郊�X�g
    std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>> openList(
        [](Node* a, Node* b)
        {
            return a->Evaluation() > b->Evaluation();
        });

    //�o�H�����ׂĕ�
    std::vector< std::vector<bool>> closed(rows, std::vector<bool>(cols, false));

    //�J�n�n�_�����X�g�ɒǉ����ĒT���J�n
    Node* startNode = new Node(start.second, start.first, 0, Heuristic(start.first, start.second, goal.first, goal.second), nullptr);
    openList.push(startNode);

    //���X�g����ɂȂ�܂ŒT��
    while (!openList.empty())
    {
        //���X�g�̏��߂����݂̃m�[�h�ɂ���
        Node* current = openList.top();
        openList.pop();

        if (current->nodePos.x == goal.second && current->nodePos.y == goal.first)
        {
            // �S�[���ɓ��B������p�X�Ƀf�[�^��ǉ�
            std::vector< std::pair<int, int>> path;
            while (current != nullptr) {
                path.emplace_back(static_cast<int>(current->nodePos.x), static_cast<int>(current->nodePos.y));

                //���݂̃m�[�h�����e�m�[�h�ɐ؂�ւ���
                current = current->parent;
            }

            //���Ԃ��t�Ȃ̂Ŗ߂��ďo�����o�H��Ԃ�
            reverse(path.begin(), path.end());
            return path;
        }
        else
        {
            //*���݂̃m�[�h�̏ꏊ�����
            closed[static_cast<int>(current->nodePos.x)][static_cast<int>(current->nodePos.y)] = true;

            // �㉺���E���̃}�X��T��
            for (const auto& dir : directions)
            {
                int newX = static_cast<int>(current->nodePos.x) + dir.first;
                int newY = static_cast<int>(current->nodePos.y) + dir.second;

                //�X�e�[�W���ɂ��������x�T�������ꏊ���m�F
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols)
                {
                    if ((stage[newX][newY].type & AISLE) && !closed[newX][newY])
                    {
                        //���T���Ȃ猻�݂̃m�[�h��e�Ƃ��ĐV�K�m�[�h�����X�g�ɒǉ�
                        int newG = current->nodeCost + 1;
                        int newH = Heuristic(newX, newY, goal.first, goal.second);
                        Node* newNode = new Node(newX, newY, newG, newH, current);
                        openList.push(newNode);
                    }
                }
            }
        }
    }

    // �S�[���ɓ��B�ł��Ȃ��ꍇ�͋�̃p�X��Ԃ�
    return {};
}

Astar::Node::Node(int x, int y, int cost, int dis, Node* parent)
    :nodePos(VGet(x,y,0))
    ,nodeCost(cost)
    ,nodeDistance(dis)
    ,parent(parent)
{
    //�����Ȃ�
}
