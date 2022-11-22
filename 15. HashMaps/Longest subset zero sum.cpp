#include <iostream>
using namespace std;

#include<unordered_map>

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here

    int sum = 0;
    unordered_map<int,int> keeper;
    int ans_subset_length = 0;
    for(int i{0};i<n;i++)
    {
        sum = sum + arr[i];
        if(sum == 0)
        {
            ans_subset_length = max(i,ans_subset_length);
            continue;
        }
        if(keeper.count(sum) > 0)
        {
            int curr_subset_length = i - (keeper[sum] + 1);
            ans_subset_length = max(ans_subset_length,curr_subset_length);
        }
        else keeper[sum] = i;
    }

    return ans_subset_length + 1;

}
int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}