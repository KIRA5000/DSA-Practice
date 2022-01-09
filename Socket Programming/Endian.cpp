#include <iostream>

void check(char *val, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2x ", val[i]);
    }
}

int main()
{
    int i = 0x1234567;

    check((char*)&i, sizeof(i));
}