#include <iostream>
#include <vector>

// rearragne sorted array in form of 6, 1, 5, 2, 4, 3

void rearrange(std::vector<long long>& arr) 
{
    int n = arr.size();
    long long temp[n] = {0};
    
    for (int i = 0; i < (n/2); i++)
    {
        temp[2*i + 1] = arr[i];
    }
    
    int j = 0;
    
    for (int i = n - 1; i >= (n/2); i--)
    {
        temp[2*j] = arr[i];
        j++;
    }
    
    for (int i = 0; i < n; i ++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int size;
    std::vector<long long> arr;

    std::cout << "How many values do you need?" << std::endl;
    std::cin >> size;

    for (int i = 0; i < size; i ++)
    {
        long long val;
        std::cin >> val;

        arr.push_back(val);
    }

    rearrange(arr);
}