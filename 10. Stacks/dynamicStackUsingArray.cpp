#include <bits/stdc++.h>
#define MIN -1;

using namespace std;


class StackUsingArray{
    private:
        int *arr;
        int nextIndex;
        int capacity;

    public:


        StackUsingArray(){
            arr = new int [5];
            nextIndex = 0;
            capacity = 5;
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
                int *newArr = new int [2 * capacity];
                for(int i{0};i<capacity;i++)
                    newArr[i] = arr[i];
                delete [] arr;
                arr = newArr;
                capacity *= 2;   
            }
            arr[nextIndex] = data;
            nextIndex++;
            cout<<data<<" is pushed to stack"<<endl;
        }

        void pop(){
            if(nextIndex == 0)
            {
                cout<<"Stack is Empty";
                // return MIN;
            }
            nextIndex--;
            cout<<arr[nextIndex]<<" is poped out of stack"<<endl;
        }

        int onTop(){
            if(nextIndex == 0)
                return MIN;
            return arr[nextIndex];
        }



};


int main(){
    StackUsingArray s;
    int data = 0;

    cin>>data;
    while(data != -1){
       s.push(data);
        cin>>data;
    }

    int pop = 0;

    cout<<"Pop the stack using 1"<<endl;
    cin>>pop;

    while(pop){
        s.pop();
        cin>>pop;
    }

    cout<<s.onTop()<<endl;

    





    
    
    return 0;
}