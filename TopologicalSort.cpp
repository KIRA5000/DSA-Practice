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

    void addnode(int x, int y)
    {
        adj[x].push_back(y);
    }

    void topoUtil(std::stack<int>& st, std::vector<bool>& visited, int index)
    {
        visited[index] = true;

        for (auto it = adj[index].begin(); it != adj[index].end(); it++)
        {
            if (!visited[*it])
            {
                topoUtil(st, visited, *it);
            }
        }

        st.push(index);
    }

    void topologicalSort()
    {
        std::stack<int> st;
        std::vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                topoUtil(st, visited, i);
            }
        }

        while (!st.empty())
        {
            std::cout << st.top() << "->";
            st.pop();
        }

        std::cout << std::endl;
    }
};

void test(std::vector<std::pair<int, int>> v, int n)
{
    Graph g(n);

    for (int i = 0; i < n; i++)
    {
        g.addnode(v[i].first, v[i].second);
    }

    g.topologicalSort();
}

int main()
{
    int size;

    std::cout << "Size: ";
    std::cin >> size;

    std::vector<std::pair<int, int>> g;

    for (int i = 0; i < size; i++)
    {
        int a, b;
        std::cin >> a >> b;

        g.push_back({a, b});
    }

    std::cout << "Number of vertices: ";
    std::cin >> size;

    test(g, size);

    return 0;
}