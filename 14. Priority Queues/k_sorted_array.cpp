#include <iostream>
#include <queue>

using namespace std;

void kSortedArrays(int *arr, int n, int k)
{
    priority_queue<int> pq;
    for (int i{0}; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i{0}; i < n; i++)
    {
        int top = pq.top();
        pq.pop();
        arr[i] = top;
        if((k+i)<n) pq.push(arr[k+i]);
        
    }
}

int main()
{
    int arr[5] = {10,12,6,7,9};
    kSortedArrays(arr,5,3);
    for(int i{0};i<5;i++) cout<<arr[i]<<" ";    
    cout<<endl;

    return 0;
}