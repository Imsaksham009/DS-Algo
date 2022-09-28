#include <bits/stdc++.h>
using namespace std;

template <typename T>

class QueueUsingArray
{
private:
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(T s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    void enqueue(int element)
    {
        if(size == capacity)
        {
            cout<<"Queue is Full!"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1)%capacity;
        size++;
        if (firstIndex == -1)
            firstIndex = 0;
    }

    T dequeue()
    {
        if (firstIndex == -1 || isEmpty()){
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
        {
            T a = data[firstIndex];
            firstIndex = (firstIndex + 1)%capacity;
            size--;
            if(size == 0){
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

    bool isEmpty()
    {
        return size == 0;
    }

    T front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
};


int main(){
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(100);
    q.enqueue(200);
    cout<<q.front()<<endl;




}