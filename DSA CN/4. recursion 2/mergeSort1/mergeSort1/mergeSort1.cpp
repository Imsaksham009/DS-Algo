#include <iostream>

using namespace std;


void merge(int* arr, int s, int e) {

    int mid = (s + e) / 2;

    int size1 = (mid - s) + 1;
    int size2 = e - mid;
    int size3 = (e - s) + 1;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    int* arr3 = new int[size3];

    int j = s;
    for (int i{ 0 }; i < size1; i++)
        arr1[i] = arr[j + i];
    int l = mid + 1;
    for (int i{ 0 }; i < size2; i++) {
        arr2[i] = arr[l + 1];
    }

    int m{ 0 }, n{ 0 }, k{ 0 };
    while (m < size1 && n < size2)
    {
        if (arr1[m] < arr2[n])
            arr3[k++] = arr1[m++];
        else
            arr3[k++] = arr2[n++];
    }

    while (m < size1)
        arr3[k++] = arr1[m++];


    while (n < size2)
        arr3[k++] = arr2[n++];

    for (int i = 0; i < size3; i++)
        arr[j + i] = arr3[i];


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

void mergeFun(int* arr, int s, int e) {
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mergeFun(arr, s, mid);
    mergeFun(arr, mid + 1, e);
    merge(arr, s, e);

}

void mergeSort(int arr[], int size) {
    // Write your code here
    int s = 0;
    int e = size - 1;
    mergeFun(arr, s, e);
}


int main() {
    int length;
    cin >> length;
    int* input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++) {
        cout << input[i] << " ";
    }
}