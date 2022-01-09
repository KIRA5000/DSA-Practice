#include <iostream>
#include <vector>

int trappingRain(std::vector<int> pillars)
{
    std::vector<int> maxL, maxR;
    int l = 0, r = 0;

    for (int i = 0; i < pillars.size(); i++)
    {
        if (pillars[i] > l)
        {
            l = pillars[i];
        }

        maxL.push_back(l);

        if (pillars[pillars.size() - 1 -i] > r)
        {
            r = pillars[pillars.size() - 1 - i];
        }

        maxR.push_back(r);
    }

    int sum = 0;
    std::reverse(maxR.begin(), maxR.end());

    for (int i = 0; i < pillars.size(); i++)
    {
        int min = ((maxL[i] < maxR[i]) ? maxL[i] : maxR[i]);

        sum += min - pillars[i];
    }

    return sum;
}

int main()
{
    std::vector<int> pillars = {3,0,0,2,0,4};

    std::cout << "Trapped Water: " << trappingRain(pillars) << std::endl;
    return 0;
}