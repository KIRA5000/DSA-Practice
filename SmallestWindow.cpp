#include <iostream>

using namespace std;

// smallest substring of s to contain all elements of p
string smallestWindow(string s, string p)
{
    if (p.size() > s.size())
    {
        return "-1";
    }
    
    unordered_map<int, int> mp;
    
    for (int i = 0; i < p.size(); i++)
    {
        mp[p[i]]++;
    }
    
    int count = mp.size();
    
    int i = 0, j = 0, size = INT_MAX, start = -1;
    
    while (j < s.size())
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }
        
        if (count == 0)
        {
            while (count == 0)
            {
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    
                    if (mp[s[i]] == 1)
                    {
                        count++;
                    }
                }
                
                i++;
            }
            
            if (size > (j - i + 2))
            {
                size = (j - i + 2);
                start = i - 1;
            }
        }
        
        j++;
    }
    
    return ((size == INT_MAX) ? "-1" : s.substr(start, size));
}