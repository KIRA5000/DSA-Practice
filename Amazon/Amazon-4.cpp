#include <iostream>
#include <vector>

#include <bits/stdc++.h>

void rotate(std::vector<std::vector<int>>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::reverse(arr[i].begin(), arr[i].end());
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            std::swap(arr[i][j], arr[j][i]);
        }
    }
}

int main()
{
    int size;
    std::vector<std::vector<int>> arr;

    std::cout << "Enter size: ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        std::vector<int> row;

        for (int j = 0; j < size; j++)
        {
            int val;

            std::cin >> val;

            row.push_back(val);
        }

        arr.push_back(row);
    }

    rotate(arr);

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {
            std::cout << arr[i][j] << " ";
        }

        std::cout << std::endl;
    }
}
