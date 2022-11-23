#include <iostream>
#include <climits>

using namespace std;

int minCostPath(int **input, int **output, int m, int n, int i = 0, int j = 0)
{
    if (i >= m || j >= n)
        return INT_MAX;
    if (output[i][j] != -1)
        return output[i][j];

    int ans = input[i][j] + min(minCostPath(input, output, m, n, i + 1, j), min(minCostPath(input, output, m, n, i, j + 1), minCostPath(input, output, m, n, i + 1, j + 1)));

    output[i][j] = ans;
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;

    int **input = new int *[m];
    for (int i{0}; i < m; i++)
    {
        input[i] = new int[n];
    }
    for (int i{0}; i < m; i++)
    {
        for (int j{0}; j < n; j++)
            cin >> input[i][j];
    }

    int **output = new int *[m];
    for (int i{0}; i < m; i++)
    {
        output[i] = new int[n];
    }
    for (int i{0}; i < m; i++)
    {
        for (int j{0}; j < n; j++)
            output[i][j] = -1;
    }
    output[m - 1][n - 1] = input[m - 1][n - 1];
    cout << minCostPath(input, output, m, n) << endl;

    for (int i{0}; i < m; i++)
    {
        delete[] input[i];
    }
    delete[] input;
    for (int i{0}; i < m; i++)
    {
        delete[] output[i];
    }
    delete[] output;

    return 0;
}