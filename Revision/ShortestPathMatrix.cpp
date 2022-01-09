#include <iostream>
#include <vector>
#include <queue>

bool isSafe(std::vector<std::vector<int>>& arr, int x, int y)
{
    return ((x < arr.size()) && (y < arr[x].size()) && (x >= 0) && (y >= 0) && (arr[x][y] != 0));
}

int shortestDistance(std::vector<std::vector<int>>& arr, std::pair<int, int> start, std::pair<int ,int> dest)
{
    std::queue<std::pair<int, int>> que;
    std::vector<int> row(arr.size(), INT_MAX);
    std::vector<std::vector<int>> dist(arr[0].size(), row);

    que.push(start);
    dist[start.first][start.second] = 0;

    int x[] = {0, 0, 1, -1};
    int y[] = {1, -1, 0, 0};

    while (!que.empty())
    {
        auto cord = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isSafe(arr, cord.first + x[i], cord.second + y[i]))
            {
                if ((dist[cord.first][cord.second] + 1) < dist[cord.first + x[i]][cord.second + y[i]])
                {
                    que.push({cord.first + x[i], cord.second + y[i]});
                    dist[cord.first + x[i]][cord.second + y[i]] = dist[cord.first][cord.second] + 1;
                }
            }
        }
    }

    std::cout << "Your distance matrix: " << std::endl;

    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist[i].size(); j++)
        {
            std::cout << dist[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return ((dist[dest.first][dest.second] == INT_MAX) ? -1 : dist[dest.first][dest.second]);
}

int main()
{
    int size;

    std::cout << "Size: ";
    std::cin >> size;

    std::vector<std::vector<int>> arr;

    for (int i = 0; i < size; i++)
    {
        std::vector<int> row;

        for (int j = 0; j < size; j++)
        {
            int ele;
            std::cin >> ele;

            row.push_back(ele);
        }

        arr.push_back(row);
    }

    std::cout << "Shortest Distance: " << shortestDistance(arr, {0, 0}, {3, 3}) << std::endl;

    return 0;
}