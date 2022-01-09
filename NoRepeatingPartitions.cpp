#include <iostream>
#include <bits/stdc++.h>

int count(std::string str)
{
    std::unordered_map<int, int> m;

    for (int i = str.size() -1; i >=0; i--)
    {
        if (m.find(str[i]) == m.end())
        {
            m.insert({str[i], i});
        }
    }

    int k = m[str[0]];
    int r = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (i > k)
        {
            r++;
        }

        k = std::max(k, m[str[i]]);
    }

    r++;

    return r;
}