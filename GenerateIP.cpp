#include <iostream>
#include <vector>
#include <set>

using namespace std;

void check(string s, string left, int count, set<string>& ret)
{
    if ((count == 3) && (left.size() != 0) && (atoi(left.c_str()) < 256))
    {
        ret.insert(s + left);
        return;
    }
    
    for (int i = 0; i < left.size() - 1; i++)
    {
        string sub = left.substr(1);
        
        if (atoi(s.c_str() + left[0]) < 256)
        check(s + left[0] + '.', sub, count + 1, ret);
        
        if (sub.size() > (3 - count))
        {
            check(s + left[0], sub, count, ret);
        }
    }
}

vector<string> genIp(string &s) 
{
    set<string> ret;
    
    if (s.size() >= 4)
    {
        check("", s, 0, ret);
    }
    
    return vector<string>(ret.begin(), ret.end());
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    auto ret = genIp(str);

    cout << "All fissible IP:" << endl;

    for (int i = 0; i < ret.size(); i++)
    {
        cout << i + 1 << ". " << ret[i] << endl;
    }

    return 0;
}