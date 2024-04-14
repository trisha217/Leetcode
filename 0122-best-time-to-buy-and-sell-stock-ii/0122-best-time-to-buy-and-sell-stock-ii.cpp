class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        // Create a DP table to memoize results
        vector<int> ahead(2,0),cur(2,0);

        // Base condition: When we have no stocks left, the profit is 0.
        ahead[0] = ahead[1] = 0;

        int profit;

        // Loop through the array in reverse order
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) { // We can buy the stock
                    profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
                }

                if (buy == 1) { // We can sell the stock
                    profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
                }

                cur[buy] = profit;
            }
            ahead = cur;
        }

        // The maximum profit is stored in dp[0][0] after all calculations
        return ahead[0];
    }
};