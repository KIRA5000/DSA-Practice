#include <iostream>
#include <vector>

void maxSum(std::vector<int>& arr)
{
    int max_so_far = INT_MIN;
    int max_till_here = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        max_till_here += arr[i];

        if (max_till_here < 0)
        {
            max_till_here = 0;
        }
        else
        {
            if (max_till_here > max_so_far)
            {
                max_so_far = max_till_here;
            }
        }
    }

    std::cout << "Max sum: " << max_so_far << std::endl;
}

int main()
{
    std::vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    maxSum(arr);

    return 0;
}