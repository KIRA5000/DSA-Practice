#include <iostream>
#include <vector>

// this solution is based on knapsack

bool isSubset(std::vector<int> arr, int n, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    else if (sum < 0)
    {
        return false;
    }

    if ((arr.size() == 0) || (n == 0))
    {
        return false;
    }

    return ((isSubset(arr, n - 1, sum)) || (isSubset(arr, n - 1, sum - arr[n])));
}

void MinSubset(std::vector<int> arr, int n, int sum, int currSum, int& diff)
{
    if (((sum - currSum) < diff) && (sum != currSum))
    {
        diff = sum - currSum;
    }

    if (n == 0)
    {
        return;
    }

    MinSubset(arr, n - 1, sum, currSum, diff);
    MinSubset(arr, n - 1, sum, currSum + arr[n], diff);
}

int main()
{
    //std::vector<int> arr = {1, 2, 3};
    //int sum = 5;

    //std::cout << "Does sum exists: " << ((isSubset(arr, arr.size() - 1, sum)) ? "True" : "False") << std::endl;

    std::vector<int> arr = {1, 6, 11, 5};
    int sum = 23;
    int diff = INT_MAX;
    MinSubset(arr, arr.size() - 1, sum, 0, diff);

    std::cout << "Min diference in 2 subsets: " << diff << std::endl;

    return 0;
}