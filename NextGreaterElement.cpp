#include <iostream>
#include <vector>
#include <stack>
#include <climits>

std::vector<int> getNextGreaterElement(std::vector<int>& arr)
{
    int max;
    std::stack<std::pair<int, int>> st;
    std::vector<int> ret(arr.size(), INT_MIN);

    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            st.push({arr[i], i});
            continue;
        }

        if (st.top().first >= arr[i])
        {
            st.push({arr[i], i});
        }
        else if (st.top().first < arr[i])
        {
            while ((!st.empty()) && (st.top().first < arr[i]))
            {
                auto val = st.top();
                st.pop();
                ret[val.second] = arr[i];
            }
            
            st.push({arr[i], i});
        }
    }

    for (int i = 0; i < ret.size(); i++)
    {
        if (ret[i] == INT_MIN)
        {
            ret[i] = -1;
        }
    }

    return ret;
}

int main()
{
    int size;

    std::cout << "Size: ";
    std::cin >> size;

    std::vector<int> arr;

    for (int i = 0; i < size; i++)
    {
        int val;
        std::cin >> val;

        arr.push_back(val);
    }

    auto ret = getNextGreaterElement(arr);

    for (int i = 0; i < ret.size(); i++)
    {
        std::cout << ret[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}