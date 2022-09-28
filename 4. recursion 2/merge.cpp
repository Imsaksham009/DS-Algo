#include<iostream>

using namespace std;

void merge(int* arr, int s, int e) {

    int mid = (s + e) / 2;

    int size1 = mid + 1;
    int size2 = e - mid;
    int size3 = e + 1;
    
    int arr1[size1];
    int arr2[size2];
    int arr3[size3];

    for (int i{ 0 }; i < size1; i++)
        arr1[i] = arr[i];
    for (int i{ 0 }; i < size2; i++) {
        arr2[i] = arr[mid + i + 1];
    }

    int m{ 0 }, n{ 0 }, k{ 0 };
    while (m < size1 && n < size2)
    {
        if (arr1[m] < arr2[n])
        {
            arr3[k] = arr1[m];
            k++;
            m++;
        }
        else
        {
            arr3[k] = arr2[n];
            k++;
            n++;
        }
    }

    while (m < size1)
    {
        arr3[k] = arr1[m];
        k++;
        m++;
    }

    while (n < size2)
    {
        arr3[k] = arr2[n];
        k++;
        n++;
    }


    for (int i{ 0 }; i < size3; i++)
    {
        arr[i] = arr3[i];
    }

    //delete[] arr1;
    //delete[] arr2;
   // delete[] arr3;
}

void mergeFun(int* arr, int s, int e) {
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mergeFun(arr, s, mid);
    mergeFun(arr, mid + 1, e);
    merge(arr, s, e);

}


int main() {
    int arr[10] = { 5,4,9,8,2,0,3,1,6,7 };

	int s = 0;
	int e = 9;
	mergeFun(arr, s, e);
	for (int i = 0; i < 10; i++) {
		cout<< arr[i]<<" ";
	}
	cout << endl;


	return 0;


}