class Solution {
public:
    // int f(int ind, int buy, int cap, vector<int> &prices,vector<vector<vector<int>>> &dp){
    //     int profit;
    //     //base case
    //     if(ind == prices.size() || cap == 0){
    //         return 0;
    //     }
    //     //if value is already computed
    //     if(dp[ind][buy][cap]!=-1){
    //         return dp[ind][buy][cap];
    //     }
    //     if(buy){
    //         profit = max(-prices[ind] + f(ind+1,0,cap,prices,dp), 0 + f(ind+1,1,cap,prices,dp));
    //     }
    //     else{
    //         profit = max(prices[ind] + f(ind+1,1,cap-1,prices,dp), 0 + f(ind+1,0,cap,prices,dp));
    //     }
    //     return dp[ind][buy][cap] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit;
        vector<vector<int>> ahead(2,vector<int> (3,0));
        vector<vector<int>> cur(2,vector<int> (3,0));
        //recurrence
        for(int ind = n-1;ind>=0;ind--){
            for(int buy =0;buy<=1;buy++){
                for(int cap =1;cap<=2;cap++){
                    if(buy){
                        cur[buy][cap] = max(-prices[ind] + ahead[0][cap], 0 + ahead[1][cap]);
                    }                    
                    else{
                           cur[buy][cap] = max(prices[ind] + ahead[1][cap-1], 0 + ahead[0][cap]);
                    }
                }
            }
            ahead = cur;
        }
        return ahead[1][2];
        //return f(0,1,2,prices,dp);
    }
};