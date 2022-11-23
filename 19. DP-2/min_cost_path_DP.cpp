#include <iostream>
#include <climits>

using namespace std;

int minCostPath(int **input, int m, int n, int **output)
{

    // fill last row(backwards) of output
    for (int i = n - 2; i >= 0; i--)
        output[m - 1][i] = output[m - 1][i + 1] + input[m - 1][i];

    // fill last collumn (upwards) of output
    for (int i = m - 2; i >= 0; i--)
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];

    // fill rest of the cells of the output
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = input[i][j] + min(output[i + 1][j], min(output[i][j + 1], output[i + 1][j + 1]));
        }
    }

    return output[0][0];
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
        output[i] = new int[n];
    output[m - 1][n - 1] = input[m - 1][n - 1];

    cout << minCostPath(input, m, n, output) << endl;

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