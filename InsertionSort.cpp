#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
            else
            {
                break;
            }
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

    insertionSort(arr);

    std::cout << "Output: " << std::endl;

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}