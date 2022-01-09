#include <iostream>
#include <vector> 
#include <map>

bool check(std::vector<std::string> words)
{
    char lastCh = words[0].back();

    std::map<char, std::string> mp;

    for (int i = 0; i < words.size(); i++)
    {
        mp.insert({words[i][0], words[i]});
    }

    while (true)
    {
        if (mp.find(lastCh) != mp.end())
        {
            auto temp = mp[lastCh];
            mp.erase(lastCh);
            lastCh = temp.back();
        }
        else
        {
            return false;
        }

        if (mp.empty())
        {
            return true;
        }
    }
}

int main()
{
    std::vector<std::string> words = {"for", "geek", "rig", "kaf"};

    std::cout << "Words can be circled: " << ((check(words)) ? "True" : "False") << std::endl;
    return 0;
}