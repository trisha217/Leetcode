class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int up = INT_MAX;
        int left = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Base condition: If we are at the top-left cell (0, 0), there is one way.
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else{
                    if (i > 0)
                        up = dp[i-1][j];
                    if (j > 0)
                        left = dp[i][j-1];
                    dp[i][j] = min(up,left) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1]; 
    }
};