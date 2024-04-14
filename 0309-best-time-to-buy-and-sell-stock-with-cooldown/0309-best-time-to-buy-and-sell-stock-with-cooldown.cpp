class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        // Create a DP table to memoize results
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        int profit;

        // Loop through the array in reverse order
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) { // We can buy the stock
                    profit = max(0 + dp[ind + 1][1], -Arr[ind] + dp[ind + 1][0]);
                }
                else { // We can sell the stock
                    profit = max(0 + dp[ind + 1][0], Arr[ind] + dp[ind + 2][1]);
                }

                dp[ind][buy] = profit;
            }
        }

        // The maximum profit is stored in dp[0][1] after all calculations
        return dp[0][1];
    }
};