#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> arr)
{
    int max = 1;
    vector<int> temp(arr.size(), 1);

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if ((arr[i] < arr[j]) && (temp[i] >= temp[j]))
            {
                temp[j] = temp[i] + 1;

                if (temp[j] > max)
                {
                    max = temp[j];
                }
            }
        }
    }

    return max;
}

int main()
{
    int size;

    cout << "Size: ";
    cin >> size;

    vector<int> arr;

    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;

        arr.push_back(val);
    }

    cout << "Max Increasing sequence: " << LIS(arr) << endl;

    return 0;
}