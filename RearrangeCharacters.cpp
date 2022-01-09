#include <iostream>
#include <stack>

bool reArrangeCharacters(std::string str)
{
    std::string newStr;
    std::stack<int> st;

    newStr += str[0];

    for (int i = 1; i < str.size(); i++)
    {
        std::cout << "Element: " << str[i] << std::endl;

        if (str[i] == newStr[newStr.size() - 1])
        {
            std::cout << "Stack push" << std::endl << std::endl;
            st.push(str[i]);
        }
        else
        {
            std::cout << "New str push" << std::endl << std::endl;
            
            newStr += str[i];

            while (!st.empty())
            {
                if (st.top() != newStr[newStr.size() -1])
                {
                    newStr += st.top();
                    st.pop();
                }
                else
                {
                    break;
                }
            }

            std::cout << "newStr: " << newStr << std::endl;
        }
    }

    return st.empty();
}

int main()
{
    std::string str;

    std::cout << "Enter a string: ";
    std::cin >> str;

    std::cout << "Is it rearrangable: " << (reArrangeCharacters(str) ? "True" : "False") << std::endl;

    return 0;
}