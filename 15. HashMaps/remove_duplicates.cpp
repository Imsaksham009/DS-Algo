#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> remove_duplicates(int *arr, int n)
{
    vector<int> ans;

    unordered_map<int, bool> check;

    for(int i{0};i<n;i++)
    {
        check[arr[i]] = false;
    }

    for (int i{0}; i < n; i++)
    {
        if (check[arr[i]] == false)
        {
            ans.push_back(arr[i]);
            check[arr[i]] = true;
        }

    }
    return ans;
}

int main()
{
    int arr[22] = {1,2,3,2,1,3,1,2,4,5,4,5,6,4,7,8,5,1,5,8,9,5};
    vector<int> ans = remove_duplicates(arr,22);
    for(int i{0};i<ans.size();i++)
    cout<<ans[i]<<" ";
}