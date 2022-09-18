#include <iostream>

using namespace std;


int partition(int* a, int s, int e) {
	int l{ 0 };
	int g{ 0 };
	for (int i= (s + 1); i <= e; i++) {
		if (a[i] <= a[s])
			l++;
		else
			g++;
	}
	int fi = l + s;
	swap(a[fi], a[s]);

	int j = s;
	int k = fi + 1;

	while (j < fi) {
		if (a[j] < a[fi])
			j++;
		else {
			while (k <= e) {
				if (a[k] > a[fi])
					k++;
				else {
					swap(a[j], a[k]);
					break;
				}
			}
			j++;
		}
	}

	return fi;


}

void quickSort(int* a, int s, int e) {
	if (s >= e)
		return;
	int c = partition(a, s, e);
	quickSort(a, s, c - 1);
	quickSort(a, c + 1, e);
}





int main(){
	int n{ 0 };
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int s = 0;
	int e = n - 1;

	quickSort(arr, s, e);


	for (int i = 0; i < n; i++)
		cout << arr[i]<<" ";

	cout << endl;
	delete[] arr;

	return 0;
}

