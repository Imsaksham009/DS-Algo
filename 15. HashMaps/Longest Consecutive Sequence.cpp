#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    unordered_map<int, int> keeper;
    for (int i{0}; i < n; i++)
        keeper[arr[i]]++;

    vector<int> ans;

    int maxCount = 0;
    int count = 0;

    for (int i{0}; i < n; i++)
    {
        if (keeper.count(arr[i] - 1) > 0)
            continue;
        int j = arr[i];

        while (keeper.count(j) == 1)
        {
            count++;
            j++;
        }

        if (count == 1 && maxCount == 0)
        {
            maxCount = count;
            ans.push_back(arr[i]);
        }

        if (count > maxCount)
        {
            if (maxCount == 1)
            {
                ans.pop_back();
            }
            else if (maxCount > 1)
            {
                ans.pop_back();
                ans.pop_back();
            }
            ans.push_back(arr[i]);
            ans.push_back(--j);
            maxCount = count;
        }
        count = 0;
    }

    return ans;
}