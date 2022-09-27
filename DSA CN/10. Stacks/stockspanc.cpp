#include <bits/stdc++.h>
using namespace std;
int* stockSpan(int *price, int size)  {
	// Write your code here
    stack<int> s;
    s.push(0);
    int *arr=new int [size];
    arr[0] = 1;
	for(int i{1};i<size;i++){
        while(!s.empty() && price[i]>price[s.top()]){
            s.pop();
        }
        if(s.empty()){
            arr[i] = i + 1;
        }
        else
        	arr[i] = i - s.top();
        s.push(i);
    }
    return arr;
}


int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}