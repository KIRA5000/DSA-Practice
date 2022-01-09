#include <iostream>
#include <vector>

struct Job
{
    int index, start, duration, priority;
};

void jobScheduling(std::vector<Job>& jobs)
{
    for (int i = 0; i < jobs.size(); i++)
    {
        
    }
}

int main()
{
    int size;
    std::vector<Job> jobs;

    std::cout << "How many Jobs?: ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        Job j;
        j.index = i;

        std::cout << "Start time: ";
        std::cin >> j.start; 

        std::cout << "Duration: ";
        std::cin >> j.duration; 

        std::cout << "Priority: ";
        std::cin >> j.priority; 

        std::cout << std::endl;

        jobs.push_back(j);
    }

    jobScheduling(jobs);
}