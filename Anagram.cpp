#include <iostream>
#include <map>

bool isAnagram(const std::string& a, const std::string& b)
{
    std::map<char, int> check;

    for (int i = 0; i < a.size(); i++)
    {
        char ch = a[i];

        if (check.find(ch) != check.end())
        {
            check[ch] += 1;
        }
        else
        {
            check.insert({ch, 1});
        }
    }

    for (int i = 0; i < b.size(); i++)
    {
        char ch = b[i];

        if (check.find(ch) != check.end())
        {
            check[ch] -= 1;
        }
        else
        {
            check.insert({ch, -1});
        }
    }

    for (auto it = check.begin(); it != check.end(); it++)
    {
        if (it->second != 0)
        {
            return false;
        }
    }

    return true;
}

int main ()
{
    std::string str1, str2;

    std::cout << "Enter 2 strings: ";
    std::cin >> str1 >> str2;

    std::cout << "Are they anagrams: " << ((isAnagram(str1, str2)) ? ("True") : ("False")) << std::endl;

    return 0;
}