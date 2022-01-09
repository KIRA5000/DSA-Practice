#include <iostream>
#include <vector>

class PQ
{
    std::vector<int> ele;

    int parent(int i)
    {
        return ((i - 1)/ 2);
    }

    int left(int i)
    {
        return (2*i + 1);
    }

    int right(int i)
    {
        return (2*i + 2);
    }

    void heapify_down(int i)
    {
        int l = left(i);
        int r = right(i);

        int largest = i;

        if ((l < ele.size()) && (ele[l] > ele[i]))
        {
            largest = l;
        }

        if ((r < ele.size()) && (ele[r] > ele[largest]))
        {
            largest = r;
        }

        if (largest != i)
        {
            std::swap(ele[largest], ele[i]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i)
    {
        if ((i != 0) && (ele[parent(i)] < ele[i]))
        {
            std::swap(ele[i], ele[parent(i)]);

            heapify_up(parent(i));
        }
    }

    public:

    size_t size()
    {
        return ele.size();
    }

    bool empty()
    {
        return (ele.size() == 0);
    }

    void push(int val)
    {
        ele.push_back(val);

        heapify_up(ele.size() - 1);
    }

    void pop()
    {
        if (ele.size() == 0)
        {
            std::cout << "Priority_Queue is empty" << std::endl;
            return;
        }

        ele[0] = ele.back();
        ele.pop_back();

        heapify_down(0);
    }

    int top()
    {
        if (ele.size() == 0)
        {
            std::cout << "Priority_Queue is empty" << std::endl;
            return -1;
        }

        return ele[0];
    }
};

int main()
{
    PQ que;
    que.push(2);
    que.push(1);
    que.push(3);
    que.push(5);
    que.push(0);

    while(!que.empty())
    {
        std::cout << que.top() << "->";
        que.pop();
    }

    std::cout << std::endl;

    return 0;
}