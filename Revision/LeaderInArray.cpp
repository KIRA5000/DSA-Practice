#include <iostream>
#include <vector>
#include <stack>

std::stack<int> getLeaders(std::vector<int> arr)
{
    std::stack<int> st;

    for (int i = arr.size() -1; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push(arr[i]);
        }
        else
        {
            if (st.top() < arr[i])
            {
                st.push(arr[i]);
            }
        }
    }

    return st;
}

int main()
{
    int size;
    std::vector<int> arr;

    std::cout << "Size: ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        int ele;
        std::cin >> ele;

        arr.push_back(ele);
    }

    std::cout << "Leaders are: " << std::endl;
    auto st = getLeaders(arr);

    while(!st.empty())
    {
        std::cout << st.top() << std::endl;
        st.pop();
    }
    
    return 0;
}