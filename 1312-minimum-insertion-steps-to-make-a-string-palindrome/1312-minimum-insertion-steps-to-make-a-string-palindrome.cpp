class Solution {
public:
    int minInsertions(string x) {
        string y = x;
        reverse(y.begin(),y.end());
        int n=x.size(),m=y.size();
        int dp[n+1][m+1];
        //base case ( i==0 || j==0) return 0;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return n - dp[n][m];
    }
};