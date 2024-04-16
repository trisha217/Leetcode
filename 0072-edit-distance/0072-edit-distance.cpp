class Solution {
public:
    
    int solve(int i, int j, string x, string y, vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if(x[i] == y[j]){
            return dp[i][j] = 0 + solve(i-1,j-1,x,y,dp);
        }
            return dp[i][j] = min(1 + solve(i-1,j-1,x,y,dp),min(1 + solve(i,j-1,x,y,dp),1 + solve(i-1,j,x,y,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //base cases
        for(int j = 0;j<=m;j++){
            dp[0][j] = j;
        }
        for(int i = 1;i<=n;i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(1 + dp[i-1][j-1], min(1+ dp[i-1][j], 1 + dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};