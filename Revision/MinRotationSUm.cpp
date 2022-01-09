#include <iostream>
#include <vector>

int MinimumSum(std::vector<int> arr)
{
    int ret = INT_MAX;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    int currSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currSum += arr[i]*i;
    }

    ret = currSum;

    for (int i = 1; i < arr.size(); i++)
    {
        auto nextSum = currSum - (sum - arr[i - 1]) + arr[i - 1]*(arr.size() - 1);

        currSum = nextSum;

        ret = ((ret < currSum) ? ret : currSum);
    }

    return ret;
}

int main()
{
    std::vector<int> arr = {8, 3, 1, 2};

    std::cout << "Minimum sum of all the rotations: " << MinimumSum(arr) << std::endl;
    return 0;
}