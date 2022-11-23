#include <iostream>
#include <climits>

using namespace std;

int minCostPath(int **input, int m, int n, int i = 0, int j = 0)
{
    if (i >= m || j >= n)
        return INT_MAX;

    if (i == (m - 1) && j == (n - 1))
        return input[i][j];

    int start = input[i][j];

    return start + min(minCostPath(input, m, n, i, j + 1), min(minCostPath(input, m, n, i + 1, j), minCostPath(input, m, n, i + 1, j + 1)));
}


int main()
{
    int m,n;
    cin>>m>>n;

    int **input = new int*[m];
    for(int i{0};i<m;i++)
    {
        input[i] = new int[n];
    }
    for(int i{0};i<m;i++)
    {
        for(int j{0};j<n;j++)
        cin>>input[i][j];
    }
    cout<<minCostPath(input,m,n)<<endl;
}