#include <iostream>
#include <vector>

bool isSafe(std::vector<std::vector<int>> grid, int val, int i, int j)
{
    return ((i >= 0) && (j >= 0) && (i < grid.size()) && (j < grid[i].size()) && (grid[i][j] > val));
}

int maxPath(std::vector<std::vector<int>> grid, int i, int j)
{
    int a = 1, b = 1;

    if (isSafe(grid, grid[i][j], i + 1, j))
    {
        a = 1 + maxPath(grid, i + 1, j);
    }
    
    if (isSafe(grid, grid[i][j], i, j + 1))
    {
        b = 1 + maxPath(grid, i, j + 1);
    }

    return std::max(a, b);
}

int main()
{
    int size;

    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    std::vector<std::vector<int>> grid;

    for (int i = 0; i < size; i++)
    {
        std::vector<int> row;

        for (int j = 0; j < size; j++)
        {
            int val;
            std::cin >> val;

            row.push_back(val);
        }

        grid.push_back(row);
    }

    std::cout << "Max length in matrix is: " << maxPath(grid, 0, 0) << std::endl;

    return 0;
}