#include <bits/stdc++.h>

using namespace std;
template <typename T>

class dQueue
{
private:
    T *data;
    int size;
    int capacity;
    int firstIndex;
    int nextIndex;

public:
    dQueue()
    {
        data = new T[5];
        size = 0;
        capacity = 5;
        firstIndex = -1;
        nextIndex = 0;
    }

    void enqueue(int s)
    {

        if (size == capacity)
        {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i{0}; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            nextIndex = capacity;
            capacity *= 2;
            firstIndex = 0;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = s;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
        if (firstIndex == -1)
            firstIndex = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    T dequeue()
    {
        if (firstIndex == -1 || isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
        {
            T a = data[firstIndex];
            firstIndex = (firstIndex + 1) % capacity;
            size--;
            if (size == 0)
            {
                firstIndex = -1;
                nextIndex = 0;
            }
            return a;
        }
    }
    int getSize()
    {
        return size;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }
};

int main()
{
    dQueue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(400);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;



    return 0;
}