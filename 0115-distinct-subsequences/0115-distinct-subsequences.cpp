class Solution {
public:
    int solve(int ind1, int ind2,string x, string y, vector<vector<int>> &dp){
        if(ind2<0){
            return 1;
        }
        if(ind1<0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(x[ind1]==y[ind2]){
            return dp[ind1][ind2] = solve(ind1-1,ind2-1,x,y,dp) + solve(ind1-1,ind2,x,y,dp);

        }
        return dp[ind1][ind2] = solve(ind1-1,ind2,x,y,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};