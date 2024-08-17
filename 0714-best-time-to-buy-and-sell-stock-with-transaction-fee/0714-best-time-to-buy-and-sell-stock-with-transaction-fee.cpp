class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        dp[n][0] = dp[n][1] = 0;
        long profit=0;
        //n days
        for(int i=n-1;i>=0;i--){
            //buy
            for(int j=0;j<2;j++){
                if(j==0){
                    int op1 = 0 + dp[i+1][0];
                    int op2 = -prices[i] + dp[i+1][1];
                    profit = max(op1,op2);
                }
                else{
                    int op1 = 0 + dp[i+1][1];
                    int op2 = prices[i] - fee + dp[i+1][0];
                    profit = max(op1,op2);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][0];
    }
};