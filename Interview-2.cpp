#include <iostream>

int equilibriumPoint(long long a[], int n) {
    
    if (n == 1)
    {
        return 1;
    }
    
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        sum += a[i];
    }
    
    int backSum = sum, frontSum = 0;
    
    for (int i = 2; i < n; i++)
    {
        frontSum += a[i - 2];
        backSum -= a[i - 1];
        
        if (frontSum == backSum)
        {
            return i;
        }
    }
    
    return -1;
}
    
int main()
{
    int size;
    
    std::cout << "Enter size: ";
    std::cin >> size;
    
    long long arr[size];
    
    std::cout << "Enter elements:" << std::endl;
    
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    
    std::cout << "Your equilibrium point is: " << equilibriumPoint(arr, size) << std::endl;
    
    return 0;
}