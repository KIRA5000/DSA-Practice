#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> grid, int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (grid[i][col] == 1)
        {
            return false;
        }
    }

    int i = row, j = col;

    while (i >= 0 && j >= 0)
    {
        if (grid[i--][j--] == 1)
        {
            return false;
        }
    }

    i = row;
    j = col;

    while (i >= 0 && j < grid[i].size())
    {
        if (grid[i--][j++] == 1)
        {
            return false;
        }
    }

    return true;
}

bool nQueen(vector<vector<int>>& grid, int row)
{
    if (row >= grid.size())
    {
        return true;
    }

    for (int i = 0; i < grid[row].size(); i++)
    {
        bool safe = isSafe(grid, row, i);

        if (safe)
        {
            grid[row][i] = 1;
            safe = nQueen(grid, row + 1);
        }

        if (safe)
        {
            return true;
        }
        else
        {
            grid[row][i] = 0;
        }
    }

    return false;
}

int main()
{
    int size;

    cout << "Enter size of the grid: ";
    cin >> size;

    vector<vector<int>> grid(size, vector<int>(size, 0));

    auto safe = nQueen(grid, 0);

    if (safe)
    {
        cout << "Grid:" << endl;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << grid[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No such solution exists" << endl;
    }

    return 0;
}