#include <iostream>

int lcs(std::string a, std::string b, int n, int m, int count)
{
    if ((n == 0) || (m == 0))
    {
        return count;
    }

    if (a[n] == b[m])
    {
        return lcs(a, b, n -1, m - 1, count + 1);
    }
    else
    {
        return (max(count, max(lcs(a, b, n -1, m, 0), lcs(a, b, n, m - 1, 0))));
    }
}