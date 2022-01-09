#include <iostream>
#include <vector>

class heap
{
    std::vector<int> ele;

    int parent(int i)
    {
        return (i - 1)/2;
    }

    int left(int i)
    {
        return 2*i + 1;
    }

    int right(int i)
    {
        return 2*(i + 1);
    }

    void heapify_up(int i)
    {
        if ((i != 0) && (ele[parent(i)] > ele[i]))
        {
            std::swap(ele[i], ele[parent(i)]);
            heapify_up(parent(i));
        }
    }

    void heapify_down(int i)
    {
        int l = left(i);
        int r = right(i);

        int largest = i;

        if ((l < ele.size()) && (ele[l] < ele[i]))
        {
            largest = l;
        }
        if ((r < ele.size()) && (ele[r] < ele[largest]))
        {
            largest = r;
        }

        if (largest != i)
        {
            std::swap(ele[largest], ele[i]);
            heapify_down(largest);
        }
    }

    public:

    void push(int data)
    {
        ele.push_back(data);
        heapify_up(ele.size() - 1);
    }

    int top()
    {
        if (ele.size() != 0)
        {
            return ele[0];
        }
    }

    void pop()
    {
        ele[0] = ele.back();
        ele.pop_back();

        heapify_down(0);
    }

    bool empty()
    {
        return ele.size() == 0;
    }
};

int main()
{
    heap h;

    h.push(2);
    h.push(1);
    h.push(0);
    h.push(5);
    h.push(4);

    while (!h.empty())
    {
        auto i = h.top();
        h.pop();

        std::cout << i << "->";
    }
    std::cout << std::endl;

    return 0;
}