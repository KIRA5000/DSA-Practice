#include <iostream>
#include <vector>
#include <set>

void DFS(std::vector<int> coins, std::vector<int>* g, int i, int sum, int n, int& count)
{
    if (sum > n)
    {
        return;
    }
    else if (sum == n)
    {
        count++;
        return;
    }

    for (auto it = g[i].begin(); it != g[i].end(); it++)
    {
        DFS(coins, g, *it, sum + coins[i], n, count);
    }
}

int count(std::vector<int> coins, int n)
{
    std::vector<int>* g = new std::vector<int>[coins.size()];

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = i; j < coins.size(); i++)
        {
            g[i].push_back(j);
        }
    }

    int count = 0;

    for (int i = 0; i < coins.size(); i++)
    {
        DFS(coins, g, i, 0, n, count);
    }

    return count;
}

int main()
{
    std::vector<int> coins = {1, 2, 3};

    std::cout << "Possible ways: " << count(coins, 4) << std::endl;
    return 0;
}