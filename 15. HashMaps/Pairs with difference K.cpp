#include <iostream>
using namespace std;
#include <unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k)
{
    // Write your code here
    unordered_map<int, bool> isVisited;
    unordered_map<int, int> keeper;

    for (int i{0}; i < n; i++)
    {
        keeper[arr[i]]++;
        isVisited[arr[i]] = false;
    }

    int count = 0;

    for (int i{0}; i < n; i++)
    {
        if (isVisited[arr[i]] == true)
            continue;

        int remaining_sum = arr[i] - k;

        if (keeper.count(remaining_sum) > 0)
        {
            if (remaining_sum == arr[i])
            {
                count = count + ((keeper[arr[i]] * (keeper[arr[i]] - 1))) / 2;
            }

            else
                count = count + (keeper[arr[i]] * keeper[remaining_sum]);
            isVisited[remaining_sum] = true;
        }

        isVisited[arr[i]] = true;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}