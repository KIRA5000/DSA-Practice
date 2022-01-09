#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> allSubstring(std::string str)
{
    std::vector<std::string> ret;

    for (int i = 0; i <str.size(); i++)
    {
        for (int j = str.size() - 1; j >= i; j--)
        {
            ret.push_back(str.substr(i, str.size() - j + i));
        }
    }

    return ret;
}

int main()
{
    std::string str;

    std::cout << "Enter a string: ";
    std::cin >> str;

    auto vect = allSubstring(str);

    
}