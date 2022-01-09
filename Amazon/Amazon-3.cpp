#include <iostream>
#include <vector>

void printNextGreatestElement(std::vector<int> arr)
{
    int max = -1;
    int lastValue = 0;

    std::vector<int> output;

    for (size_t i = arr.size() - 1; i >= 0; i--)
    {
        if (i == arr.size() - 1)
        {
            output.insert(output.begin(), max);

            max = arr[i];
            lastValue = arr[i];
        }
        else
        {
            output.insert(output.begin(), max);

            lastValue = arr[i];
            if (arr[i] > lastValue)
            {
                max = arr[i];
            }
        }
    }

    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << "->";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {4, 5, 2, 25};

    printNextGreatestElement(arr);

    return 0;
}