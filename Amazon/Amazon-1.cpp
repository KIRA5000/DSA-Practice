#include <iostream>
#include <vector>

#include <bits/stdc++.h>

auto getNLarge(std::vector<int>& arr, int& size)
{
    std::vector<int> ret;

    std::sort(arr.begin(), arr.end());

    for (int i = arr.size() - size; i < arr.size(); i++)
    {
        ret.push_back(arr[i]);
    }

    return ret;
}

int main()
{
    int size;
    std::vector<int> arr;

    std::cout << "Enter size od array: ";
    std::cin >> size;

    std::cout << "Enter elements of array:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        int ele;
        std::cin >> ele;

        arr.push_back(ele);
    }

    std::cout << "How many largest elements you need?" << std::endl;

    std::cin >> size;

    auto ret = getNLarge(arr, size);

    std::cout << "Largest k elements:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << ret[i] << std::endl;
    }
}