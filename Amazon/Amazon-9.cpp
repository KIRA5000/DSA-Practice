#include <iostream>
#include <vector>
#include <map>

std::vector<std::vector<int>> getCloseLoc(std::vector<std::vector<int>>& arr, int size)
{
    std::map<int, std::vector<int>> m;

    for (int i = 0; i < arr.size(); i++)
    {
        int dist = 0;
        auto row = arr[i];

        for (int j = 0; j < row.size(); j++)
        {
            dist += row[j]*row[j];
        }

        m.insert({dist, row});
    }

    std::vector<std::vector<int>> ret;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (ret.size() == size)
        {
            break;
        }

        ret.push_back(it->second);
    }

    return ret;
}

int main()
{
    int size;
    std::vector<std::vector<int>> arr;

    std::cout << "How many loactions: ";
    std::cin >> size;

    std::cout << "Enter x,y loacation:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        int a, b;

        std::cin >> a >> b;

        std::vector<int> temp;

        temp.push_back(a);
        temp.push_back(b);

        arr.push_back(temp);
    }

    std::cout << "How many restaurants you need?" << std::endl;
    std::cin >> size;

    auto loc = getCloseLoc(arr, size);

    std::cout << "Your locations: " << std::endl;

    for (int i = 0; i < loc.size(); i++)
    {
        std::cout << "(" << loc[i][0] << "," << loc[i][1] << ")" << std::endl;
    }

    return 0;
}