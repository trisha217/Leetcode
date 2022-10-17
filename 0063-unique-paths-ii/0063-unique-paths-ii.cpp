class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //vector<vector<int>>v=obstacleGrid;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector< vector<int>> dp(n,vector<int>(m, 0));
    int i,j,k;
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        else if(n==1 && m==1)
        {
            if(obstacleGrid[0][0]==1) return 0;
            else return 1;
        }
        
        dp[0][0]=0;
        i=1;
        j=1;
        k=n;
       
        for(i=1;i<n;i++)
        {
            if(obstacleGrid[i][0]==0) dp[i][0]=1;
            else {k=i;break;}
        }
        cout<<i<<" ";
        if(i!=n) k=i;
        for(i=k;i<n;i++) dp[i][0]=-1;
        k=m;
       for(j=1;j<m;j++)
        {
            if(obstacleGrid[0][j]==0) dp[0][j]=1;
            else {k=j;break;}
        }
        cout<<j<<" ";
        if(j!=m) k=j;
        for(j=k;j<m;j++) dp[0][j]=-1;
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(obstacleGrid[i][j]==1) dp[i][j]=-1;
                else {
                    if(dp[i-1][j]!=-1 && dp[i][j-1]!=-1)
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    else if(dp[i-1][j]!=-1)
                        dp[i][j]=dp[i-1][j];
                    else if(dp[i][j-1]!=-1)
                         dp[i][j]=dp[i][j-1];
                    else
                        dp[i][j]=-1;
                        
                    
                }
            }
        }
        if(dp[n-1][m-1]<0) return 0;
        return dp[n-1][m-1];
    }
};