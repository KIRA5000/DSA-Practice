// count min amount of char to make it pallindrome

#include <iostream>

int minCount(std::string str, int i, int j, int count)
{
    if (i == j)
    {
        return 0;
    }
    else if (i == j - 1)
    {
        if (str[i] == str[j])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        int temp;

        if (str[i] != str[j])
        {
            count = std::min(count, std::min(minCount(str, i + 1, j, count), minCount(str, i, j - 1, count)) + 1);
        }
        else
        {
            count = std::min(count, minCount(str, i + 1, j - 1, count));
        }

        return count;
    }
}

int main()
{
    int count = INT_MAX;
    std::string str;

    std::cout << "Enter a string: ";
    std::cin >> str;

    std::cout << "Count to make string a palindrome: " << minCount(str, 0, str.size() - 1, count) << std::endl;

    return 0;
}