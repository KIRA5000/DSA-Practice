#include <iostream>
#include <vector>
#include <climits>

int getLen(std::vector<std::vector<int>>& arr, int i, int j)
{
    if ((i >= arr.size()) || (i < 0))
    {
        return INT_MAX;
    }
    if ((j >= arr[i].size()) || (j < 0))
    {
        return INT_MAX;
    }

    if (arr[i][j] == 9)
    {
        return 1;
    }
    else if (arr[i][j] == 0)
    {
        return INT_MAX;
    }
    else
    {
        int a = getLen(arr, i+1, j);
        int b = getLen(arr, i, j+1);
        int c = getLen(arr, i+1, j+1);
        int d = getLen(arr, i, j-1);
        int e = getLen(arr, i-1, j);
        int f = getLen(arr, i-1, j-1);

        int min1 = std::min(a, b);
        int min2 = std::min(c, d);
        int min3 = std::min(e, f);
        int min4 = std::min(min1, min2);
        
        return (std::min(min4, min3) + 1);
    }
}

int minPathLength(std::vector<std::vector<int>>& arr)
{
    return getLen(arr, 0, 0);
}

int main()
{
    int size;
    std::vector<std::vector<int>> arr;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    std::cout << "Enter values in matrix: "  << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::vector<int> col;

        for (int j = 0; j < size; j++)
        {
            int val;

            std::cin >> val;

            col.push_back(val);
        }

        arr.push_back(col);
    }

    auto pLen = minPathLength(arr);

    std::cout << "Minimum path length: " << pLen << std::endl;

    return 0;
}