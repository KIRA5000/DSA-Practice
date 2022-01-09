#include <iostream>
#include <vector>
#include <stack>
#include <list>

class Graph
{
    int v;
    std::list<int>* adj;

    public:

    Graph(int v)
    {
        this->v = v;
        adj = new std::list<int>[v];
    }

    void addNode(int x, int y)
    {
        adj[x].push_back(y);
    }

    void DFS(std::stack<int>& st, std::vector<bool>& visited, int index)
    {
        visited[index] = true;

        for (auto it = adj[index].begin(); it != adj[index].end(); it++)
        {
            if (!visited[*it])
            {
                DFS(st, visited, *it);
            }
        }

        st.push(index);
    }

    std::stack<int> toplogicalOrder()
    {
        std::stack<int> st;
        std::vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                DFS(st, visited, i);
            }
        }

        return st;
    }
};

void printOrder(std::vector<std::string>& words, int n, int k)
{
    Graph g(k);

    for (int i = 0; i < n - 1; i++)
    {
        auto word1 = words[i];
        auto word2 = words[i + 1];

        for (int j = 0; j < std::min(word1.size(), word2.size()); j++)
        {
            if (word1[j] != word2[j])
            {
                g.addNode(word1[j] - 'a', word2[j] - 'a');
            }
        }
    }

    auto st = g.toplogicalOrder();

    while (!st.empty())
    {
        std::cout << (char)(st.top() + 'a') << " ";
        st.pop();
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words = {"caa", "aaa", "aab"};

    printOrder(words, 3, 3);

    return 0;
}