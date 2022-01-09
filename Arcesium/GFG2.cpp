// https://www.geeksforgeeks.org/sort-a-stack-using-recursion/

#include <iostream>
#include <stack>

void insert(std::stack<int>& st, int data)
{
    if (st.empty())
    {
        st.push(data);
    }
    else
    {
        if (st.top() < data)
        {
            int temp = st.top();
            st.pop();

            insert(st, data);

            st.push(temp);
        }
        else
        {
            st.push(data);
        }
    }
}

void reverse(std::stack<int>& st)
{
    if(!st.empty())
    {
        int data = st.top();
        st.pop();
        reverse(st);

        insert(st, data);
    }
}

int main()
{
    int size;
    std::stack<int> st;

    std::cout << "Size of stack: ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        int ele;
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> ele;

        st.push(ele);
    }

    std::cout << "Sorted stack: " << std::endl;
    reverse(st);

    while (!st.empty())
    {
        std::cout << st.top() << "->";
        st.pop();
    }
    std::cout << std::endl;

    return 0;
}