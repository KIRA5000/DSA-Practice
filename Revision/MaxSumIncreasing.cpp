#include <iostream>
#include <vector>

int DFS(std::vector<int>& arr, std::vector<int>* g, std::vector<bool>& visited, int i, int& max)
{
    int sum = arr[i];
    visited[i] = true;

    for (auto it = g[i].begin(); it != g[i].end(); it++)
    {
        if (!visited[*it])
        {
            auto temp = arr[i] + DFS(arr, g, visited, *it, max);
            max = ((temp > max) ? temp : max);
            sum = ((temp > sum) ? temp : sum);
        }
    }

    return sum;
}

int getLongestSum(std::vector<int>& arr)
{
    std::vector<int>* g = new std::vector<int>[arr.size()];

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] < arr[j])
            {
                g[i].push_back(j);
            }
        }
    }

    std::vector<bool> visited(arr.size(), false);
    int max = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (!visited[i])
        {
            DFS(arr, g, visited, i, max);
        }
    }

    return max;
}

int main()
{
    std::vector<int> arr = {1, 101, 2, 3, 100};

    std::cout << "Max Sum Increasing: " << getLongestSum(arr) << std::endl;

    return 0;
}