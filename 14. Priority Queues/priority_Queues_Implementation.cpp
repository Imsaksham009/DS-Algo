#include <iostream>
#include <vector>
#include<climits>

using namespace std;

class PriorityQueue
{
private:
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    // returns true is pq is empty
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // return the size of the pq
    int getSize()
    {
        return pq.size();
    }

    // return minimum number
    int getMin()
    {
        if (isEmpty())
            return 0;
        return pq.at(0);
    }

    void insert(int data)
    {
        pq.push_back(data);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq.at(childIndex) < pq.at(parentIndex))
            {
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
                break;

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
            return 0;

        int ans = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();

        // down-heapify
        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;

        while (leftChildIndex < pq.size())
        {
            int minChild=INT_MIN;
            if(rightChildIndex < pq.size()) minChild = min(pq[parentIndex], min(pq[leftChildIndex], pq[rightChildIndex]));

            if (minChild == pq[leftChildIndex])
            {
                swap(pq[parentIndex], pq[leftChildIndex]);
                parentIndex = leftChildIndex;
            }
            else if (rightChildIndex < pq.size() && minChild == pq[rightChildIndex])
            {
                swap(pq[parentIndex],pq[rightChildIndex]);
                parentIndex = rightChildIndex;
            }
        }

        return ans;
    }
};

int main()
{
    PriorityQueue p1;
}