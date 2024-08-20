class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 0){
                    // Base condition: If we are at the top-left cell (0, 0), there is one way.
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                        continue; // Skip the rest of the loop and continue with the next iteration.
                    }
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1]; 
    }
};