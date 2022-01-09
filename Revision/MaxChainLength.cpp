#include <iostream>
#include <vector>

int DFS(std::vector<int>* g, std::vector<bool>& visited, int i, int& size)
{
    int ret = 1;
    visited[i] = true;

    for (auto it = g[i].begin(); it != g[i].end(); it++)
    {
        if (!visited[*it])
        {
            auto temp = 1 + DFS(g, visited, *it, size);

            size = ((temp > size) ? temp : size);
            ret = ((temp > ret) ? temp : ret);
        }
    }

    return ret;
}

int maxChainLen(std::vector<std::pair<int, int>>& chain)
{
    std::vector<int>* g = new std::vector<int>[chain.size()];

    for (int i = 0; i < chain.size() - 1; i++)
    {
        for (int j = i + 1; j < chain.size(); j++)
        {
            if (chain[i].second < chain[j].first)
            {
                g[i].push_back(j);
            }
        }
    }

    std::vector<bool> visited(chain.size(), false);
    int size = 0;

    for (int i = 0; i < g->size(); i++)
    {
        if (!visited[i])
        {
            DFS(g, visited, i, size);
        }
    }

    return size;
}

int main()
{
    std::vector<std::pair<int, int>> chain = {{5, 24}, {15, 28}, {27, 40}, {39, 60}, {50, 90}};

    std::cout << "Max chain: " << maxChainLen(chain) << std::endl;

    return 0;
}