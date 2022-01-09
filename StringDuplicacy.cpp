#include <iostream>

using namespace std;

string check(string& curr, int i)
{
    if (curr.size() == 0)
    {
        return string();
    }
    if (i == curr.size() - 1)
    {
        if (curr[i] == curr[i - 1])
        {
            return string();
        }
        else
        {
            return string(1, curr[i]);
        }
    }
    else
    {
        int j = i + 1;
        int k = abs(i - 1);
        
        if ((curr[i] != curr[j]) && (curr[i] != curr[k]))
        {
            return curr[i] + check(curr, i+1);
        }
        else
        {
            return check(curr, i+1);   
        }
    }
}

int main ()
{
    string str;
    
    std::cout << "String: ";
    std::cin >> str;
    
    std::cout << check(str, 0) << std::endl;
}