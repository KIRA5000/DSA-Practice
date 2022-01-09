#include <iostream>
#include <vector>
#include <map>

class DS
{
    std::vector<int> v;
    std::map<int, int> m;

    public:

    void add(int x)
    {
        if (m.find(x) != m.end())
        {
            return;
        }
        else
        {
            v.push_back(x);
            m.insert({x, v.size() - 1});
        }
    }

    void remove(int x)
    {
        if (m.find(x) == m.end())
        {
            std::cout << "Element Node found!" << std::endl;
        }
        else
        {
            int index = m[x];
            int ele = v.back();
            m.erase(x);

            std::swap(v[m[x]], v[v.size() - 1]);
            v.pop_back();

            m[ele] = index;
        }
    }
};