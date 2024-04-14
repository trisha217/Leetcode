class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        // Create a DP table to memoize results
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        
        // Loop through the array in reverse order
        for (int ind = n - 1; ind >= 0; ind--) {
            dp[ind][1] = max(0 + dp[ind + 1][1], -Arr[ind] + dp[ind + 1][0]);
            dp[ind][0] = max(0 + dp[ind + 1][0], Arr[ind] + dp[ind + 2][1]);
        }

        // The maximum profit is stored in dp[0][1] after all calculations
        return dp[0][1];
    }
};