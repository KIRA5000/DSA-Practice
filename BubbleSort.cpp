#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool swapped = false;

        for (int j = 0; j < arr.size() - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int size;
    std::vector<int> arr;
    
    std::cout << "Enter size of the array: ";
    std::cin >> size;

    std::cout << "Enter elements:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        int val;

        std::cin >> val;

        arr.push_back(val);
    }

    bubbleSort(arr);

    std::cout << "Output: " << std::endl;

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}