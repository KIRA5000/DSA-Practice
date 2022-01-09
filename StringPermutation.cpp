#include <iostream>
#include <vector>

using namespace std;

void perm(string str, string result)
{   
    if (!str.size())
    {
        cout << result << endl;
    }
    else
    {
        for (int i = 0; i < str.size(); i++)
        {
            auto left = str.substr(0, i);
            auto right = str.substr(i+1);
            
            perm(left + right, result + str[i]);
        }
    }
}

int main()
{
    string str;

    std::cout << "Enter a string: ";
    std::cin >> str;

    perm(str, "");
}