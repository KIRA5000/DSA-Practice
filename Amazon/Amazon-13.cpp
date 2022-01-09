#include <iostream>
#include <vector>

bool isSafe(std::vector<std::vector<int>>& m, int i, int j, std::vector<std::vector<bool>>& isVisited)
{
    return ((i >= 0) && (j >= 0) && (i < m.size()) && (j < m[i].size()) && (m[i][j] == 1) && (isVisited[i][j] == false));
}

void DFS(std::vector<std::vector<int>>& m, int i, int j, std::vector<std::vector<bool>>& isVisited)
{
    int row[] = {0, 0, 1, 1, 1, -1, -1, -1};
    int col[] = {1, -1, 1, -1, 0, 1, -1, 0};

    isVisited[i][j] = true;

    for (int c = 0; c < 8; c++)
    {
        if (isSafe(m, i + row[c], j + col[c], isVisited))
        {
            DFS(m, i + row[c], j + col[c], isVisited);
        }
    }
}

int checkIslands(std::vector<std::vector<int>>& m)
{
    std::vector<std::vector<bool>> isVisited;

    for (int i = 0; i < m.size(); i++)
    {
        std::vector<bool> row;

        for (int j = 0 ; j < m[i].size(); j++)
        {
            row.push_back(false);
        }

        isVisited.push_back(row);
    }

    int count = 0;

    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            if ((m[i][j] != 0) && (!isVisited[i][j]))
            {
                DFS(m, i, j, isVisited);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int size;

    std::cout << "Size of you matrix: ";
    std::cin >> size;

    std::cout << "Enter elements of your matrix:" << std::endl;

    std::vector<std::vector<int>> m;

    for (int i = 0; i < size; i++)
    {
        std::vector<int> row;

        for (int j = 0; j < size; j++)
        {
            int val;

            std::cin >> val;

            row.push_back(val);
        }

        m.push_back(row);
    }

    std::cout << "Number of islands: " << checkIslands(m) << std::endl;

    return 0;
}