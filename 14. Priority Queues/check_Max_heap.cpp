#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    bool ans = true;

    for (int i{0}; i < n; i++) {
      int parentIndex = i;
      int leftChildIndex = 2 * parentIndex + 1;
      int rightChildIndex = 2 * parentIndex + 2;

      if (leftChildIndex < n && arr[parentIndex] < arr[leftChildIndex])
        ans = false;
      if (rightChildIndex < n && arr[parentIndex] < arr[rightChildIndex])
        ans = false;
    }
    
    return ans;

}


int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}