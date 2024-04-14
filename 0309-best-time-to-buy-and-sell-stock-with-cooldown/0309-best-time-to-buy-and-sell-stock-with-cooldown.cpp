class Solution {
public:
    int f(int ind, int buy, vector<vector<int>> &dp,vector<int>& prices,int n){
        //base case
        if (ind >= n) {
            return 0;
        }
        // If the result for this state has already been calculated, return it
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        int profit = 0;
        if (buy) { // We can buy the stock
            profit = max(0 + f(ind + 1,1,dp,prices,n), -prices[ind] + f(ind + 1, 0,dp,prices,n));
        }

        else { // We can sell the stock
            profit = max(0 + f(ind + 1,0,dp,prices,n), prices[ind] + f(ind + 2, 1,dp,prices,n));
        }

        // Store the calculated profit in the DP table and return it
        return dp[ind][buy] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans = f(0,1,dp,prices,n);
        return ans;
    }
};