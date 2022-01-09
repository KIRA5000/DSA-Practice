#include <iostream>
#include <stack>

bool checkParenthesis(std::string& str)
{
    std::stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
        {
            st.push(str[i]);
        }

        if (str[i] == ')')
        {
            if (st.size() != 0)
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if (str[i] == '}')
        {
            if (st.size() != 0)
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if (str[i] == ']')
        {
            if (st.size() != 0)
            {
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return (st.size() ? false : true);
}

int main()
{
    std::string str;

    std::cout << "Enter a string: ";
    std::cin >> str;

    std::cout << "Is paranthesis balanced: " << (checkParenthesis(str) ? "True" : "False") << std::endl;
    
    return 0;
}