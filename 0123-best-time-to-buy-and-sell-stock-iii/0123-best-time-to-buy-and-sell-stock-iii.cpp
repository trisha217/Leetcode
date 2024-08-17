class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        //base case: if( ind == n || cap == 0) return 0
        //no need of writing separately, because we have initiated eveyrthing to 0.
        long profit=0;
        //n days
        for(int i=n-1;i>=0;i--){
            //buy
            for(int j=0;j<2;j++){
                //cap - transactions
                for (int cap = 1; cap <= 2; cap++){
                   if(j==0){
                        int op1 = 0 + dp[i+1][0][cap];
                        int op2 = -prices[i] + dp[i+1][1][cap];
                        profit = max(op1,op2);
                    }
                    else{
                        int op1 = 0 + dp[i+1][1][cap];
                        int op2 = prices[i] + dp[i+1][0][cap-1];
                        profit = max(op1,op2);
                    }
                    dp[i][j][cap] = profit; 
                }
            }
        }
        return dp[0][0][2];
    }
};