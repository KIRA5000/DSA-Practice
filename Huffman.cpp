#include <iostream>
#include <vector>
#include <map>

#include <bits/stdc++.h>

static bool sortVect(std::pair<char, int> a, std::pair<char, int> b)
{
    return (a.second > b.second);
}

void huffman(std::string& str)
{
    std::map<char, int> m;
    int size = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (m.find(str[i]) != m.end())
        {
            m[str[i]] += 1;
        }
        else
        {
            m.insert({str[i], 1});
        }

        size++;
    }

    std::vector<std::pair<char, int>> vect(m.begin(), m.end());

    std::sort(vect.begin(), vect.end(), sortVect);

    
}

int main()
{
    std::string str;

    std::cout << "Enter a string: ";
    std::cin >> str;

    huffman(str);

    return 0;
}