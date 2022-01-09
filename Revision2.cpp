#include <iostream>
#include <map>

using namespace std;

int maxDivisions(string& str)
{
    map<char, int> mp;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (mp.find(str[i]) == mp.end())
        {
            mp.insert({str[i], i});
        }
    }

    int count = 0;
    int k = mp[str[0]];

    for (int i = 0; i < str.size(); i++)
    {
        if (i > k)
        {
            count++;
        }

        k = max(k, mp[str[i]]);
    }

    count++;

    return count;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Number of divisions: " << maxDivisions(str) << endl;

    return 0;
}