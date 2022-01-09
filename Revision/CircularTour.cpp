#include <iostream>
#include <vector>

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    int currentFuel = 0, prevFuel = 0, start = 0;

    for (int i = 0; i < n; i++)
    {
        currentFuel = p[i].petrol - p[i].distance;

        if (currentFuel < 0)
        {
            prevFuel = currentFuel;
            currentFuel = 0;
            start = i + 1;
        }
    }

    return (((currentFuel + prevFuel) > 0) ? start : -1);
}