#include <iostream>
#include <vector>

int NextGreater(int num)
{
    std::vector<int> arr;

    while (num >= 10)
    {
        int rem = num%10;
        arr.insert(arr.begin(), rem);
        num /= 10;
    }

    arr.insert(arr.begin(), num);
    int i;

    for (i = arr.size() -1; i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
        {
            break;
        }
    }

    if (i == 0)
    {
        return -1;
    }

    for (int j = arr.size() -1; j >= i; j--)
    {
        if (arr[j] > arr[i - 1])
        {
            std::swap(arr[j], arr[i - 1]);
        }
    }

    std::reverse(arr.begin() + i, arr.end());

    num = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        num += arr[j];
        num *= 10;
    }

    return num/10;
}

int main()
{
    int i = 23453;
    std::cout << "Next greater permutation: " << NextGreater(i) << std::endl;
    return 0;
}