#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>

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

    void DFS(std::stack<int>& st, std::vector<bool>& visited, std::vector<bool> onpath, int index, bool& condition)
    {
        visited[index] = true;
        onpath[index] = true;

        for (auto it = adj[index].begin(); it != adj[index].end(); it++)
        {
            if (onpath[*it] == true)
            {
                condition = false;
                return;
            }
            if (!visited[*it])
            {
                DFS(st, visited, onpath, *it, condition);
            }
        }

        st.push(index);
    }

    std::stack<int> toplogicalOrder(bool& condition)
    {
        std::stack<int> st;
        std::vector<bool> visited(v, false);
        std::vector<bool> onpath(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                DFS(st, visited, onpath, i, condition);
            }
        }

        return st;
    }
};

void findOrder(std::vector<std::pair<int, int>>& tasks, int n)
{
    Graph g(n);

    for (int i = 0; i < tasks.size(); i++)
    {
        g.addNode(tasks[i].second, tasks[i].first);
    }

    bool condition = true;

    auto st = g.toplogicalOrder(condition);

    while ((!st.empty()) && (condition))
    {
        std::cout << st.top() << " ";
        st.pop();
    }

    std::cout << std::endl;
}

int main()
{
    int numTasks = 4;
    std::vector<std::pair<int, int> > prerequisites;
  
    // for prerequisites: [[1, 0], [2, 1], [3, 2]]
    prerequisites.push_back({1, 0});
    // prerequisites.push_back({0, 1});
    prerequisites.push_back({2, 0});
    prerequisites.push_back({3, 1});
    prerequisites.push_back({3, 2});

    findOrder(prerequisites, numTasks);

    std::cout << std::endl;
  
    return 0;
}