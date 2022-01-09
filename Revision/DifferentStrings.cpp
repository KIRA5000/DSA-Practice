#include <iostream>
#include <map>

int howManyDiffStrings(const std::string& str)
{
    std::map<char, int> check;
    int count = 0;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (check.find(str[i]) == check.end())
        {
            check.insert({str[i], i});
        }
    }

    int k = INT_MIN;

    for (int i = 0; i < str.size(); i++)
    {
        if (k < check[str[i]])
        {
            k = check[str[i]];
        }

        if (i == k)
        {
            count++;
            k = INT_MIN;
        }
    }

    return count;
}

int main()
{
    std::string str = "aabbcc";

    std::cout << "Number of different strings: " << howManyDiffStrings(str) << std::endl;

    return 0;
}