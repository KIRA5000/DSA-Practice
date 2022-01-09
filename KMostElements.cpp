#include <iostream>
#include <vector>
#include <map>

#include <bits/stdc++.h>

bool compare(std::pair<int, int>& a, std::pair<int, int>& b)
{
    if (a.second == b.second)
    {
        return (a.first > b.first);
    }

    return (a.second > b.second);
}

auto getMaxOcc(std::vector<int>& arr, int& size)
{
    std::unordered_map<int, int> m;

    for (int i = 0; i < arr.size(); i++)
    {
        if (m.find(arr[i]) == m.end())
        {
            m.insert({arr[i], 1});
        }
        else
        {
            m[arr[i]] += 1;
        }
    }

    std::vector<std::pair<int, int>> que(m.begin(), m.end());

    std::sort(que.begin(), que.end(), compare);

    std::vector<int> ret;

    for (int i = 0; i < size; i++)
    {
        ret.push_back(que[i].first);
    }

    return ret;
}

int main()
{
    int size;

    std::cout << "Enter size of Array: ";
    std::cin >> size;

    std::vector<int> arr;

    for (int i = 0; i < size; i++)
    {
        int val;

        std::cin >> val;

        arr.push_back(val);
    }

    std::cout << "How many max elemets you need to find: ";
    std::cin >> size;

    auto ret = getMaxOcc(arr, size);

    for (int i = 0; i < ret.size; i++)
    {
        std::cout << ret[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}