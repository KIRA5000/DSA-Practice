#include <iostream>
#include <vector>

int merge(std::vector<int> arr, int i, int l, int j)
{
    int ivCount = 0, n1 = l - i + 1, n2 = j - l;
    std::vector<int> a1, a2;

    for (int k = 0; k < n1; k++)
    {
        a1.push_back(arr[i + k]);
    }

    for (int m = 0; m < n2; m++)
    {
        a2.push_back(arr[l + m + 1]);
    }

    int k = 0, m = 0, t = i;

    while (k < n1 && m < n2)
    {
        if (arr[k] <= arr[m])
        {
            arr[t++] = a1[k++];
        }
        else
        {
            arr[t++] = a2[m++];
            ivCount += n1 - k;
        }
    }

    while (k < n1)
    {
        arr[t++] = a1[k++];
    }

    while (m < n2)
    {
        arr[t++] = a2[m++];
    }

    return ivCount;
}

int mergeSort(std::vector<int> arr, int i, int j)
{
    int ivCount = 0;

    if (i < j)
    {
        int mid = (i + j)/2;
        ivCount += mergeSort(arr, i, mid);
        ivCount += mergeSort(arr, mid + 1, j);
        ivCount += merge(arr, i , mid, j);
    }

    return ivCount;
}

int countInversions(std::vector<int>& arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    std::vector<int> arr = {2, 4, 1, 3, 5};

    std::cout << "Number of inversions: " << countInversions(arr) << std::endl;
    return 0;
}