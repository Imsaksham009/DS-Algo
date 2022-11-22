#include<bits/stdc++.h>
using namespace std;

void heapSort(int arr[], int n) {
  // Write your code
  for (int i{1}; i < n; i++) {
    int childIndex = i;

    while (childIndex > 0) {
      int parentIndex = (childIndex - 1) / 2;

      if (arr[childIndex] < arr[parentIndex]) {
        swap(arr[parentIndex], arr[childIndex]);
      } else
        break;

      childIndex = parentIndex;
    }
  }

  for(int i{0};i<n;i++)
  {
    swap(arr[0],arr[n-i-1]);

    int parentIndex = 0;
    int leftChildIndex = 2*parentIndex + 1;
    int rightChildIndex = 2*parentIndex + 2;

    while(leftChildIndex < n-i-1)
    {
      int minOfChild;
      if(rightChildIndex < n-i-1)
        minOfChild = min(arr[parentIndex],min(arr[leftChildIndex],arr[rightChildIndex]));
      else
        minOfChild = min(arr[parentIndex],arr[leftChildIndex]);

        if(minOfChild == arr[leftChildIndex])
        {
          swap(arr[parentIndex],arr[leftChildIndex]);
          parentIndex = leftChildIndex;
        }
        else if(minOfChild == arr[rightChildIndex])
        {
          swap(arr[parentIndex],arr[rightChildIndex]);
          parentIndex = rightChildIndex; 
        }
        else break;

        leftChildIndex = 2*parentIndex + 1;
        rightChildIndex = 2*parentIndex + 2;
    }
  }

  // sort(arr, arr + n, greater<int>());
  //:-)  :-)  :-)  :-)  :-)  :-)  :-) :-) 
}



int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}