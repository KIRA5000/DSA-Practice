#include <iostream>
#include <vector>

int getMissingEle(std::vector<int> ele)
{
    int sum = 0;
    int expectedSum = ((ele.size() + 1)*(ele.size() + 2))/2;

    for (int i : ele)
    {
        sum += i;
    }

    return (expectedSum - sum);
}

int main()
{
    int size;
    std::vector<int> vect;

    std::cout << "Size: ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        int ele;
        std::cin >> ele;

        vect.push_back(ele);
    }

    std::cout << "Missing element: " << getMissingEle(vect) << std::endl;

    return 0;
}