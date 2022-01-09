#include <iostream>
#include <vector>
#include <stack>

class graph
{
    int v;
    std::vector<int>* adj;

    public:

    graph(int v)
    {
        this->v = v;
        adj = new std::vector<int>[v];
    }

    void addNode(int x, int y)
    {
        adj[x].push_back(y);
    }

    void DFS(int i, std::vector<bool>& visited, std::stack<int>& st)
    {
        visited[i] = true;

        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            if (!visited[*it])
            {
                DFS(*it, visited, st);
            }
        }

        st.push(i);
    }

    auto topologicalSort()
    {
        std::stack<int> st;
        std::vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                DFS(i, visited, st);
            }
        }

        return st;
    }
};

auto findOrder(std::vector<std::string>& words, int v)
{
    graph g(v);

    for (int i = 0; i < words.size() - 1; i++)
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

    auto st = g.topologicalSort();

    while(!st.empty())
    {
        std::cout << (char)(st.top() + 'a') << "->";
        st.pop();
    }
}

int main()
{
    std::vector<std::string> words = {"caa", "aaa", "aab"};

    findOrder(words, 3);

    return 0;
}