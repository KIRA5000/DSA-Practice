#include <iostream>
#include <vector>
#include <queue>

struct Cell
{
    int x;
    int y;
    int cost;
};

int myComparison(Cell& c1, Cell& c2)
{
    return (c1.cost < c2.cost);
}

int minDistance(std::vector<int>& dist, std::vector<bool>& spt)
{
    int min = INT_MAX, minIndex;

    for (int i = 0; i < dist.size(); i++)
    {
        if ((spt[i] == false) && (dist[i] <= min))
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int dijkstra(std::vector<std::vector<int>>& arr)
{
    std::vector<std::vector<int>> dist;
    std::vector<std::vector<bool>> spt;


    for (int i = 0; i < arr.size(); i++)
    {
        std::vector<int> row1;
        std::vector<bool> row2;

        for (int j = 0; j < arr[i].size(); j++)
        {
            row1[j].push_back(INT_MAX);
            row2[j].push_back(false);
        }

        dist.push_back(row1);
        spt.push_back(row2);
    }

    std::priority_queue<Cell, std::vector<Cell>, mycomparison> pq;

    dist[0][0] = 0;
    spt[0][0] = true;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int u = minDistance(dist, spt);

        spt[u] = true;
    }

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

    dijkstra(arr);
    return 0;
}