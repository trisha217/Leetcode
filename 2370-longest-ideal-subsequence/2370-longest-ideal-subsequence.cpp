class Solution {
public:
int help(int i, int n, int k, string &s, int prev,vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if(dp[i][prev]!=-1)
    {
        return dp[i][prev];
    }
    int l = 0, r = 0;
    int x = s[i] - 'a';
    if (prev == 26)
    {
        int x = s[i] - 'a';
        l = 1 + help(i + 1, n, k, s, x,dp);
        r = help(i + 1, n, k, s, prev,dp);
    }
    else
    {
        r = help(i + 1, n, k, s, prev,dp);
        if (abs(x - prev) <= k)
        {
            l = 1 + help(i + 1, n, k, s, x,dp);
        }
    }
    return dp[i][prev]=max(l,r);
}
int longestIdealString(string s, int k)
{
    int n=s.length();
    vector<vector<int>> dp(n+1,vector<int>(27,-1));
    return help(0,n,k,s,26,dp);
}
};