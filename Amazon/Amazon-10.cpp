#include <iostream>
#include <stack>

bool checkRedundant(std::string& str)
{
    std::stack<char> st;

    for (auto& ch : str)
    {
        if (st.empty())
        {
            if (ch == ')')
            {
                return true;
            }
            else if (ch == '(')
            {
                st.push('(');
            }
            else if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
            {
                st.push(ch);
            }
        }
        else
        {
            if (ch == ')')
            {
                auto top = st.top();
                st.pop();

                if (top == '(')
                {
                    return true;
                }
                else if ((top == '+') || (top == '-') || (top == '*') || (top == '/'))
                {
                    while (true)
                    {
                        top = st.top();
                        st.pop();

                        if (top == '(')
                        {
                            break;
                        }
                    }
                }
            }
            else if (ch == '(')
            {
                st.push('(');
            }
            else if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
            {
                st.push(ch);
            }
        }
    }

    return false;
}

int main()
{
    std::string str;

    std::cout << "Enter a string: ";
    std::cin >> str;

    std::cout << "Is Redundant: " << ((checkRedundant(str)) ? "True" : "False") << std::endl;

    return 0;
}