#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class cordinate
{
    public:

    int x, y;

    cordinate(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int dijkstra(std::vector<std::vector<int>>& arr, cordinate& dest)
{
    std::vector<std::vector<int>> dist;

    for (int i = 0; i < arr.size(); i++)
    {
        std::vector<int> row;

        for (int j = 0; j <= arr[i].size(); j++)
        {
            row.push_back(INT_MAX);
        }

        dist.push_back(row);
    }

    dist[0][0] = 0;
    std::queue<cordinate> que;

    que.push(cordinate(0, 0));
    int distance = 1;

    while(!que.empty())
    {
        int size = que.size();
        
        for (int i = 0; i < size; i++)
        {
            auto cor = que.front();
            que.pop();
            
            if ((cor.x + 1) < arr.size())
            {
                if (arr[cor.x + 1][cor.y] != 0)
                {
                    dist[cor.x + 1][cor.y] = std::min(distance, dist[cor.x + 1][cor.y]);
    
                    if (dist[cor.x + 1][cor.y] == distance)
                        que.push(cordinate(cor.x + 1, cor.y));
                }
            }
    
            if ((cor.y + 1) < arr[0].size())
            {
                if (arr[cor.x][cor.y + 1] != 0)
                {
                    dist[cor.x][cor.y + 1] = std::min(distance, dist[cor.x][cor.y + 1]);
    
                    if (dist[cor.x][cor.y + 1] == distance)
                        que.push(cordinate(cor.x, cor.y + 1));
                }
            }
    
            if (((cor.x + 1) < arr.size()) && ((cor.y + 1) < arr[0].size()))
            {
                if (arr[cor.x + 1][cor.y + 1] != 0)
                {
                    dist[cor.x + 1][cor.y + 1] = std::min(distance, dist[cor.x + 1][cor.y + 1]);
    
                    if (dist[cor.x + 1][cor.y + 1] == distance)
                        que.push(cordinate(cor.x + 1, cor.y + 1));
                }
            }
    
            if ((cor.x - 1) >= 0)
            {
                if (arr[cor.x - 1][cor.y] != 0)
                {
                    dist[cor.x - 1][cor.y] = std::min(distance, dist[cor.x - 1][cor.y]);
    
                    if (dist[cor.x - 1][cor.y] == distance)
                        que.push(cordinate(cor.x - 1, cor.y));
                }
            }
    
            if ((cor.y - 1) >= 0)
            {
                if (arr[cor.x][cor.y - 1] != 0)
                {
                    dist[cor.x][cor.y - 1] = std::min(distance, dist[cor.x][cor.y - 1]);
    
                    if (dist[cor.x][cor.y - 1] == distance)
                        que.push(cordinate(cor.x, cor.y - 1));
                }
            }
    
            if (((cor.x - 1) >= 0) && ((cor.y - 1) >= 0))
            {
                if (arr[cor.x - 1][cor.y - 1] != 0)
                {
                    dist[cor.x - 1][cor.y - 1] = std::min(distance, dist[cor.x - 1][cor.y - 1]);
    
                    if (dist[cor.x - 1][cor.y - 1] == distance)
                        que.push(cordinate(cor.x - 1, cor.y - 1));
                }
            }
        }

        distance++;
    }
    
    std::cout << "All distance: " << std::endl;
    
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                std::cout << "M ";
            }
            else
            {
                std::cout << dist[i][j] << " ";
            }
        }
        
        std::cout << std::endl;
    }
    
    return dist[dest.x][dest.y];
}

int main()
{
    int size;
    std::vector<std::vector<int>> arr;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    std::cout << "Enter values in matrix: "  << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::vector<int> col;

        for (int j = 0; j < size; j++)
        {
            int val;

            std::cin >> val;

            col.push_back(val);
        }

        arr.push_back(col);
    }

    cordinate dest(0, 0);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 9)
            {
                dest.x = i;
                dest.y = j;
            }
        }
    }

    int dist = dijkstra(arr, dest);

    std::cout << "Shortest distance is: " << dist << std::endl;

    return 0;
}