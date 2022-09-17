#include <bits/stdc++.h>

using namespace std;

class QueueUsingArray
{
private:
    int *data;
    int nextIndex;
    int firstIndex;
    int capacity;

public:
    QueueUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        firstIndex = -1;
        capacity = totalSize;
    }

    void enqueue(int element)
    {
        if (nextIndex == capacity)
            cout << "Queue is FULL" << endl;
        else
        {
            data[nextIndex] = element;
            nextIndex++;
            if (firstIndex == -1)
                firstIndex = 0;
        }
    }

    void dequeue(){
        
    }
};