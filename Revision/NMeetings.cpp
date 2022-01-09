#include <iostream>
#include <vector>

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

auto countMeetingRooms(std::vector<int>& start, std::vector<int>& end)
{
    std::vector<std::pair<int, int>> schedule;
    std::vector<bool> allocatedRoom(start.size(), false);

    for (int i = 0; i < start.size(); i++)
    {
        schedule.push_back({start[i], end[i]});
    }

    // std::sort(schedule.begin(), schedule.end(), compare);

    int noRooms = 0;

    while (true)
    {
        int lastEnd = 0;
        int count = 0;

        for (int i = 0; i < schedule.size(); i++)
        {
            if(allocatedRoom[i] == true)
            {
                continue;
            }

            if (lastEnd < schedule[i].second)
            {
                lastEnd = schedule[i].second;
                count++;
            }
        }

        if (count == 0)
        {
            break;
        }

        noRooms++;
    }

    return noRooms;
}