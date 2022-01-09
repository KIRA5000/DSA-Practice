#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isSafe(vector<vector<int>> grid, int i, int j, vector<vector<bool>> isVisited)
{
    return ((i >= 0) && (j >= 0) && (i < grid.size()) && (j < grid[i].size()) && (grid[i][j] != 0) && (grid[i][j] != 2) && (isVisited[i][j] == false));
}

int BFS(vector<vector<int>> grid, queue<pair<int, int>> que, vector<vector<bool>> isVisited)
{
    int count = 0;
    int x[] = {0, 0, 1, -1};
    int y[] = {1, -1, 0, 0};
    
    while(!que.empty())
    {
        int size = que.size();
        
        for (int t = 0; t < size; t++)
        {
            auto cor = que.front();
            que.pop();
            
            int i = cor.first;
            int j = cor.second;
            
            isVisited[i][j] = true;
            grid[i][j] = 2;
            
            for (int c = 0; c < 4; c++)
            {
                if (isSafe(grid, i + x[c], j + y[c], isVisited))
                {
                    que.push({i + x[c], j + y[c]});
                }
            }
        }
        
        if (que.size())
        {
            count++;
        }
    }
    
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    
    return count;
}

int orangesRotting(vector<vector<int>>& grid) 
{
    vector<vector<bool>> isVisited;
    
    for (int i = 0; i < grid.size(); i++)
    {
        vector<bool> row;
        
        for (int j = 0; j < grid[i].size(); j++)
        {
            row.push_back(false);
        }
        
        isVisited.push_back(row);
    }
    
    queue<pair<int, int>> que;
    
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if ((grid[i][j] == 2) && (isVisited[i][j] == false))
            {
                que.push({i, j});
            }
        }
    }
    
    return BFS(grid, que, isVisited);
}