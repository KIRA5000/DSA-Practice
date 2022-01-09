#include <iostream>

int TotalArea(std::pair<int, int> l1, std::pair<int, int> r1, std::pair<int, int> l2, std::pair<int, int> r2)
{
    int area1 = (abs(l1.first - r1.first)*abs(l1.second - r1.second));
    int area2 = (abs(l2.first - r2.first)*abs(l2.second - r2.second));

    int interArea = (abs(std::max(l2.first, l1.first) - std::min(r2.first, r1.first))*abs(std::max(l2.second, l1.second) - std::min(r2.second, r1.second)));

    return (area1 + area2 - interArea);
}

int main()
{

}