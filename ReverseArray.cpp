#include <iostream>
#include <vector>

using namespace std;

void reverseInGroups(vector<long long>& arr, int n, int k)
{
    for (int i = 0; i < n; i += k)
    {
        int left = i;
        int right = min(n - 1, i + k - 1);
        
        while (left < right)
        {
            swap(arr[left++], arr[right--]);
        }
    }
}

int main()
{
    int size;
    vector<long long> arr;

    cout << "What is the size of array: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        long long val;

        cin >> val;

        arr.push_back(val);
    }

    int k;

    cout << "Size of each group: ";
    cin >> k;

    reverseInGroups(arr, size, k);

    return 0;
}