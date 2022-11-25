#include <iostream>
#include <string>
#include <vector>
using namespace std;

//it is the brute force
int lcs(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
        return 0;

    if (s[0] == t[0])
        return 1 + lcs(s.substr(1), t.substr(1));
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        return max(a, b);
    }
}

//memoisation is used to avoid un-necessary call
int lcs_mem(string s, string t, vector<vector<int>> &dp)
{
    int m = s.size();
    int n = t.size();

    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int ans;
    if (s[0] == t[0])
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), dp);
    else
    {
        int a = lcs_mem(s.substr(1), t, dp);
        int b = lcs_mem(s, t.substr(1), dp);
        int c = lcs_mem(s.substr(1), t.substr(1), dp);
        ans = max(a, max(b, c));
    }

    dp[m][n] = ans;
    return dp[m][n];
}

//DP version
//first we fill first row and first collumn of the the dp matrix
//then the answer of the particual cell will be dependent on the up, left and up-diag cell.
//if the string character matched
//(index will be according to the size
//(eg:-s = abc,t = dbc and we are on dp1[1,3], then it means that we are checking for the string with s of size 1 and t of size 3, so we will check if s[0] == t[2]))
//if the char matches then add 1 + max of the above adjacent cells else just max of the cells
int lcs_dp(string s, string t)
{
    int m = s.size();
    int n = t.size();

    vector<vector<int>> dp1(m + 1);

    for (int i{0}; i <= m; i++)
    {
        dp1[i] = vector<int>(n + 1);
    }

    // fill horizontally first row
    for (int i{0}; i <= n; i++)
        dp1[0][i] = 0;
    // fill vertically first col
    for (int i{0}; i <= m; i++)
        dp1[i][0] = 0;

    for (int i{1}; i <= m; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp1[i][j] = 1 + max(dp1[i - 1][j - 1], max(dp1[i - 1][j], dp1[i][j - 1]));
            }
            else
                dp1[i][j] = max(dp1[i - 1][j - 1], max(dp1[i - 1][j], dp1[i][j - 1]));
        }
    }

    return dp1[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;
    // int **output = new int*[s.size()+1];
    // for(int i{0};i<=s.size();i++)
    //     output[i] = new int[t.size()+1];
    vector<vector<int>> dp(s.size() + 1);
    for (int i{0}; i <= s.size(); i++)
    {
        dp[i] = vector<int>(t.size() + 1);
        for (int j{0}; j <= t.size(); j++)
            dp[i][j] = -1;
    }
    dp[0][0] = 0;
    cout << lcs(s, t) << endl;
    cout << lcs_mem(s, t, dp) << endl;
    cout << lcs_dp(s, t) << endl;
    return 0;
}