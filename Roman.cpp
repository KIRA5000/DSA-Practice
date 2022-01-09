#include <iostream>
#include <stack>
#include <map>

std::map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

auto romanToDec(const std::string& roman)
{
    int total = 0;
    std::stack<int> st;

    for (int i = 0; i < roman.size(); i++)
    {
        char ch = roman[i];

        if (st.size())
        {
            if (st.top() >= mp[ch])
            {
                st.push(mp[ch]);
            }
            else
            {
                int val = mp[ch] - st.top();
                st.pop();
                st.push(val);
            }
        }
        else
        {
            st.push(mp[ch]);
        }
    }

    while (!st.empty())
    {
        total += st.top();
        st.pop();
    }

    return total;
}

std::string DecToRoman(int num)
{
    std::string ret;
    int temp = num;

    while (temp > 0)
    {
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            if (temp%it->second == temp)
            {
                continue;
            }
            else
            {
                if (temp%it->second == 0)
                {
                    ret += it->first;
                }
                else if ()
            }
        }
    }
}

int main()
{
    std::string roman;

    std::cout << "Enter a number in roman: ";
    std::cin >> roman;

    std::cout << "Decimal: " << romanToDec(roman) << std::endl;

    return 0;
}