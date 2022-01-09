#include <iostream>
#include <vector>

int minSwap(std::vector<int>& arr)
{
    int ret = 0;
    std::vector<bool> visited(false, arr.size());
    std::vector<std::pair<int, int>> temp;

    for (int i = 0; i < arr.size(); i++)
    {
        temp.push_back({arr[i], i});
    }

    //std::sort(temp.begin(), temp.end(), compare);

    for (int i = 0; i < arr.size(); i++)
    {
        if ((visited[i]) || (temp[i].second == i))
        {
            continue;
        }

        int j = i;
        int size = 0;

        while(!visited[j])
        {
            visited[j] = true;
            j = temp[j].second;
            size++;
        }

        if (size > 0)
        {
            ret += size - 1;
        }
    }

    return ret;
}