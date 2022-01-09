#include <iostream>
#include <vector>
#include <climits>

int maxValue(std::vector<int>& arr, int size)
{
    int sum = 0;
    int max = INT_MIN;

    for (int i = 0 ; i < size; i++)
    {
        sum += arr[i];
    }

    if (max < sum)
    {
        max = sum;
    }

    for (int i = size; i < arr.size(); i++)
    {
        sum = sum + arr[i] - arr[i - size];

        if (max < sum)
        {
            max = sum;
        }
    }

    return max;
}

int main()
{
    std::vector<int> arr= {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int size;

    std::cout << "How long size you wanna check?: ";
    std::cin >> size;

    auto max = maxValue(arr, size);

    std::cout << "Max Value: " << max << std::endl;

    return 0;
}