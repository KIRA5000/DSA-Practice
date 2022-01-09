#include <iostream>
#include <vector>

int knapSack(int W, int wt[], int val[], int n)
{
    if ((W == 0) || (n == 0))
    {
        return 0;
    }

    if (wt[n - 1] > W)
    {
        return knapSack(W, wt, val, n - 1);
    }
    else
    {
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W - wt[n - 1], wt, val, n - 1));
    }
}