#include <iostream>
#include <vector>

void findAllPerm(std::string str, int i, int j, std::vector<std::string>& ret)
{
    if (j - 1 == i)
    {
        ret.push_back(str);
    }
    else
    {
        for (int k = i; k < j; k++)
        {
            std::swap(str[i], str[k]);
            findAllPerm(str, i + 1, j, ret);
            std::swap(str[i], str[k]);
        }
    }

    return;
}

std::vector<std::string> find_permutation(std::string str)
{
    std::vector<std::string> ret;

    findAllPerm(str, 0, str.size(), ret);

    return ret;
}

int main()
{
    std::string str;

    std::cout << "Enter a string: ";
    std::cin >> str;

    auto ret = find_permutation(str);

    std::cout << "All permutations: " << std::endl;
    for (int i = 0; i < ret.size(); i++)
    {
        std::cout << i + 1 << ". " << ret[i] << std::endl;
    }

    return 0;
}