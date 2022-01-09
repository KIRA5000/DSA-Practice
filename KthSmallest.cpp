#include <iostream>
#include <vector>

#include <bits/stdc++.h>

struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int KthSmallest(std::vector<int>& arr, int n)
{
    if (n > arr.size())
    {
        return -1;
    }

    std::priority_queue<int, std::vector<int>, compare> que(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++)
    {
        que.pop();
    }

    return que.top();
}

int main()
{
    int size;

    std::cout << "Enter size: ";
    std::cin >> size;

    std::vector<int> arr;

    for (int i = 0; i < size; i++)
    {
        int val;
        std::cin >> val;

        arr.push_back(val);
    }

    std::cout << "Enter k: ";
    std::cin >> size;

    std::cout << "Your ith smallest number in array is: " << KthSmallest(arr, size) << std::endl;

    return 0;
}