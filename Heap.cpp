#include <iostream>
#include <vector>

#include<bits/stdc++.h> 

int main()
{
    std::vector<int> arr = {4, 2, 5, 3, 6, 8, 1};

    std::make_heap(arr.begin(), arr.end());

    std::cout << arr.front() << std::endl;
    arr.pop_back();

    std::pop_heap(arr.begin(), arr.end());

    std::cout << arr.front() << std::endl;
    arr.pop_back();

    return 0;
}