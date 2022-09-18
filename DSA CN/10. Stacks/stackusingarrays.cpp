#include <bits/stdc++.h>

using namespace std;


class StackUsingArray{
    private:
        int *arr;
        int nextIndex;
        int capacity;

    public:


        StackUsingArray(int totalSize){
            arr = new int [totalSize];
            nextIndex = 0;
            capacity = totalSize;
        }

        int size(){
            return nextIndex;
        }

        bool isFull(){
            return nextIndex == capacity;
        }

        bool isEmpty(){
            return nextIndex == 0;
        }

        void push(int data){
            if(nextIndex == capacity){
                cout<<"Stack is full "<<endl;
                return;
            }
            arr[nextIndex] = data;
            nextIndex++;
        }

        int pop(){
            if(nextIndex == 0)
            {
                cout<<"Stack is Empty";
                return INT_MIN;
            }
            nextIndex--;
            return arr[nextIndex];
        }



};


int main(){
    StackUsingArray s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(50);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;


    
    
    return 0;
}