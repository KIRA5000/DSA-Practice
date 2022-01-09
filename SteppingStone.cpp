#include <iostream>
#include <vector>

auto allSteppingStones(int i, int j)
{
    std::vector<int> ret;

    for (int k = i; k <= j; k++)
    {
        int ele = k;
        bool flag = true;
        int prev = -1;

        while (ele > 0)
        {
            int curr = ele%10;

            if (prev == -1)
            {
                prev = curr;
            }
            else
            {
                if (std::abs(prev - curr) != 1)
                {
                    flag = false;
                    break;
                }

                prev = curr;
            }

            ele /= 10;
        }

        if (flag)
        {
            ret.push_back(k);
        }
    }

    return ret;
}

int main()
{
    int i, j;

    std::cout << "Enter starting index: ";
    std::cin >> i;

    std::cout << "Enter end index: ";
    std::cin >> j;

    std::cout << "All stepping stones are:" << std::endl;

    auto ret = allSteppingStones(i, j);

    for (int k = 0; k < ret.size(); k++)
    {
        std::cout << ret[k] << " ";
    }

    std::cout << std::endl;

    return 0;
}