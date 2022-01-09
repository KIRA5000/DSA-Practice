#include <iostream>
#include <vector>

using namespace std;

// Concept: https://www.youtube.com/watch?v=LAKWWDX3sGw

auto lcs(string str1, string str2)
{
    vector<vector<int>> grid(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    for (int i = 0; i < str1.size(); i++)
    {
        for (int j = 0; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                grid[i + 1][j + 1] = grid[i][j] + 1;
            }
            else
            {
                grid[i + 1][j + 1] = max(grid[i][j + 1], grid[i + 1][j]);
            }
        }
    }

    return grid[str1.size()][str2.size()];
}

int main()
{
    string str1, str2;

    cout << "Enter 2 strings: ";
    cin >> str1 >> str2;

    cout << "Size of longest common subsequence: " << lcs(str1, str2) << endl;

    return 0;
}