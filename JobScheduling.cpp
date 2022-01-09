#include <iostream>
#include <vector>
#include <climits>

#include <bits/stdc++.h>

struct Job
{
    int index;
    int profit;
    int dead;
};

int getMaxDead(std::vector<Job>& jobs)
{
    int max = INT_MIN;

    for (int i = 0; i < jobs.size(); i++)
    {
        if (jobs[i].dead > max)
        {
            max = jobs[i].dead;
        }
    }

    return max;
}

static bool sortJob(Job j1, Job j2)
{
    return (j1.profit > j2.profit);
}

void jobScheduling(std::vector<Job>& jobs)
{
    int maxDead = getMaxDead(jobs);

    std::vector<int> schedule;
    int totalProfit = 0;

    for (int i = 0; i < maxDead; i++)
    {
        schedule.push_back(INT_MIN);
    }

    std::sort(jobs.begin(), jobs.end(), sortJob);

    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i].dead - 1; j >= 0; j--)
        {
            if (schedule[j] == INT_MIN)
            {
                schedule[j] = jobs[i].index;
                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    std::cout << "Which jobs we choose to take on:" << std::endl;

    for (int i = 0; i < schedule.size(); i++)
    {
        std::cout << schedule[i] << "->";
    }

    std::cout << std::endl;
    std::cout << "Total Profit: " << totalProfit << std::endl;
}

int main()
{
    int size;
    std::vector<Job> jobs;

    std::cout << "How many jobs?" << std::endl;
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        Job temp;

        std::cout << "Enter profit then deadline" << std::endl;
        std::cin >> temp.profit >> temp.dead;
        temp.index = i;

        jobs.push_back(temp);
    }

    jobScheduling(jobs);

    return 0;
}
