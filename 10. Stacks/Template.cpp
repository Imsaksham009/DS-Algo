#include <bits/stdc++.h>
using namespace std;

template <typename T>

class StackUsingArray
{
    private:
    T *arr;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        arr = new T[5];
        nextIndex = 0;
        capacity = 5;
    }

    int size()
    {
        return nextIndex;
    }

    bool isFull()
    {
        return nextIndex == capacity;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(T data)
    {
        if (nextIndex == capacity)
        {
            T *newArr = new T [2 * capacity];
            for (int i{0}; i < capacity; i++)
                newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
            capacity *= 2;
        }
        arr[nextIndex] = data;
        nextIndex++;
        cout << data << " is pushed to stack" << endl;
    }

    T pop()
    {
        if (nextIndex <= 0)
        {
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        nextIndex--;
        cout<<arr[nextIndex]<<endl;
        return arr[nextIndex];
    }

    T onTop()
    {
        if (nextIndex == 0)
            return 0;
        return arr[nextIndex-1];
    }

    
};

int main()
{
    StackUsingArray<char> s;

   s.push('a');
   s.push('b');
  s.push('v');
  s.pop();
  s.pop();
    

    cout << s.onTop() << endl;
}