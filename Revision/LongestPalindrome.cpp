#include <iostream>
#include <vector>

std::string longestPalindrome(std::string& str)
{
    std::vector<std::vector<bool>> grid(str.size(), std::vector<bool>(str.size(), false));

    for (int i = 0; i < str.size(); i++)
    {
        grid[i][i] = true;
    }

    int start = 0, maxLen = 0;

    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            grid[i][i + 1] = true;
        }

        if (maxLen != 2)
        {
            start = i;
            maxLen = 2;
        }
    }

    for (int i = 3; i < str.size(); i++)
    {
        for (int j = 0; j < str.size() - i + 1; j++)
        {
            int k = j + i - 1;

            if ((str[j] == str[k]) && (grid[j + 1][k - 1]))
            {
                grid[j][k] = true;

                if (k > maxLen)
                {
                    maxLen = k;
                    start = j;
                }
            }
        }
    }

    return str.substr(start, maxLen);
}