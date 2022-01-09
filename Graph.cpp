#include <iostream>
#include <vector>
#include <queue>
#include <list>

class Graph
{
    int vertices;
    std::list<int>* adj;

    public:

    Graph(int size)
    {
        vertices = size;

        adj = new std::list<int>[size];
    }

    void addEdge(int start, int dest)
    {
        adj[start].push_back(dest);
    }

    void BFS(int s)
    {
        std::vector<bool> isVisited;

        for (int i = 0; i < vertices; i++)
        {
            isVisited.push_back(false);
        }

        isVisited[s] = true;

        std::queue<int> que;
        que.push(s);

        while (!que.empty())
        {
            int size = que.size();

            for (int i = 0; i < size; i++)
            {
                auto node = que.front();
                que.pop();

                std::cout << node << "->";

                for(auto j = adj[node].begin(); j != adj[node].end(); j++)
                {
                    if (isVisited[*j] == false)
                    {
                        que.push(*j);
                        isVisited[*j] = true;
                    }
                }
            }
        }
    }

    void DFS(int s, std::vector<bool> isVisited)
    {
        isVisited[s] = true;
        std::cout << s << "->";

        for (auto i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if(isVisited[*i] == false)
            {
                isVisited[*i] = true;
                DFS(*i, isVisited);
            }
        }
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    std::cout << "Following is Breadth First Traversal (starting from vertex 2)" << std::endl;
    g.BFS(2);
    std::cout << std::endl;

    std::cout << "Following is Deapth First Traversal (starting from vertex 2)" << std::endl;

    std::vector<bool> isVisited;

    for (int i = 0; i < 4; i++)
    {
        isVisited.push_back(false);
    }

    g.DFS(2, isVisited);
    std::cout << std::endl;

    return 0;
}