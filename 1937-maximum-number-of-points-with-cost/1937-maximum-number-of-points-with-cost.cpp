class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        // Create a dp array where dp[row][col] represents the maximum points that can be obtained starting from the given row and column.
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        
        // Initialize the dp table with the last row of the points matrix
        for (int j = 0; j < m; j++) {
            dp[n-1][j] = points[n-1][j];
        }

        // Fill the dp table from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            // Left to right pass
            vector<long long> leftMax(m, 0);
            leftMax[0] = dp[i + 1][0];
            for (int j = 1; j < m; j++) {
                leftMax[j] = max(leftMax[j - 1] - 1, dp[i + 1][j]);
            }

            // Right to left pass
            vector<long long> rightMax(m, 0);
            rightMax[m - 1] = dp[i + 1][m - 1];
            for (int j = m - 2; j >= 0; j--) {
                rightMax[j] = max(rightMax[j + 1] - 1, dp[i + 1][j]);
            }

            // Fill dp[i][j] considering both leftMax and rightMax
            for (int j = 0; j < m; j++) {
                dp[i][j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }

        // The maximum value in the first row of the dp array is the answer
        long long ans = 0;
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[0][j]);
        }
        return ans;
    }
};
