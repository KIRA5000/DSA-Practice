#include <iostream>
#include <vector>

#include <bits/stdc++.h>

struct Job
{
    int start;
    int stop;

    Job(int start, int stop)
    {
        this->start = start;
        this->stop = stop;
    }
};

bool compare(Job& j1, Job& j2)
{
    return (j1.start < j2.start);
}

int getNumber(std::vector<int>& start, std::vector<int>& stop)
{
    std::vector<Job> schedule;
    std::vector<bool> isCovered;

    for (int i = 0; i < start.size(); i++)
    {
        Job j(start[i], stop[i]);

        schedule.push_back(j);
        isCovered.push_back(false);
    }

    std::sort(schedule.begin(), schedule.end(), compare);

    std::vector<std::vector<Job>> platforms;

    while (true)
    {
        std::vector<Job> coveredJobs;

        for (int i = 0; i < schedule.size(); i++)
        {
            if (isCovered[i] == false)
            {
                if (coveredJobs.empty())
                {
                    coveredJobs.push_back(schedule[i]);
                    isCovered[i] = true;
                }
                else if (coveredJobs[coveredJobs.size() - 1].stop <= schedule[i].start)
                {
                    coveredJobs.push_back(schedule[i]);
                    isCovered[i] = true;
                }
            }
        }

        if (coveredJobs.size() == 0)
        {
            break;
        }
        else
        {
            platforms.push_back(coveredJobs);
            coveredJobs.clear();
        }
    }

    return platforms.size();
}

int main()
{
    int size;

    std::cout << "Enter size of meetings: ";
    std::cin >> size;

    std::vector<int> start, stop;

    for (int i = 0; i < size; i++)
    {
        int a, b;

        std::cin >> a >> b;

        start.push_back(a);
        stop.push_back(b);
    }

    std::cout << "Number of stations required: " << getNumber(start, stop) << std::endl;

    return 0;
}