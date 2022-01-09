#include <iostream>
#include <vector>
#include <map>

bool anyTriplet(std::vector<int>& arr)
{
    std::map<int, int> m;

    for (int i = 0; i < arr.size(); i++)
    {
        m.insert({arr[i] * arr[i], 1});
    }

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; i < arr.size(); j++)
        {
            auto sum = arr[i]*arr[i] + arr[j]*arr[j];

            if (m[sum] == 1)
            {
                return true;
            }
        }
    }

    return false;
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

    bool flag = anyTriplet(arr);

    std::cout << "Triplet condition: " << ((flag) ? "true" : "false") << std::endl;

    return 0;
}