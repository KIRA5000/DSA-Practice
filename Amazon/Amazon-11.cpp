#include <iostream>
#include <vector>

using namespace std;

long long trappingWater(int arr[], int n)
{
    vector<int> left, right;
    int maxL = INT_MIN;
    int maxR = INT_MIN;
    long long sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        maxL = max(maxL, arr[i]);
        left.push_back(maxL);
        
        maxR = max(maxR, arr[n - 1- i]);
        right.push_back(maxR);
    }
    
    reverse(right.begin(), right.end());
    
    for (int i = 0; i < n; i++)
    {
        auto minVal = min(left[i], right[i]);
        sum += (minVal - arr[i]);
    }
    
    return sum;
}

int main()
{
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Max water that can be trapped: " << trappingWater(arr, size) << endl;

    delete arr;

    return 0;
}