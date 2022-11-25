#include <iostream>
#include <string>
#include <vector>
using namespace std;


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

int lcs_mem(string s, string t, vector<vector<int>> &dp)
{
    int m = s.size();
    int n = t.size();

    if(m == 0 || n == 0)
     return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int ans;
    if (s[0] == t[0])
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), dp);
    else
    {
        int a = lcs_mem(s.substr(1),t,dp);
        int b = lcs_mem(s,t.substr(1),dp);
        int c = lcs_mem(s.substr(1),t.substr(1),dp);
        ans = max(a,max(b,c));
    }

    dp[m][n] = ans;
    return dp[m][n];
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
    cout << lcs(s, t)<<endl;
    cout << lcs_mem(s, t, dp)<<endl;
    return 0;
}