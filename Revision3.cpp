#include <iostream>

using namespace std;

int palindrome(string& str, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (i == j - 1)
    {
        if (str[i] == str[j])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    if (str[i] == str[j])
    {
        return palindrome(str, i + 1, j - 1);
    }
    else
    {
        return min(1 + palindrome(str, i + 1, j), 1 + palindrome(str, i, j - 1));
    }
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Number of divisions: " << palindrome(str, 0, str.size() - 1) << endl;

    return 0;
}