class Solution {
public:

    int path(int i,vector<vector<int>>& piles, int k,vector<vector<int>> &dp){
        if(i==piles.size() || k==0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int res=path(i+1,piles,k,dp);
        int curr=0;
        int maxi=0;
        for(int j=0;j<piles[i].size() && j<k;j++){
            curr+=piles[i][j];
            maxi=max(curr+path(i+1,piles,k-j-1,dp),maxi);

        }
        return dp[i][k]=max(res,maxi);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
      //  vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
      //  return path(0,piles,k,dp);
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=k;i++)dp[n][i]=0;

        for(int i=n-1;i>=0;i--){
            for(int cap=1;cap<=k;cap++){
            int res=dp[i+1][cap];
            int curr=0;
            int maxi=0;
            for(int j=0;j<piles[i].size() && j<cap;j++){
                curr+=piles[i][j];
                maxi=max(maxi,curr+dp[i+1][cap-j-1]);
            }
            dp[i][cap]=max(maxi,res);

            }
            
        }

        return dp[0][k];
    }
};