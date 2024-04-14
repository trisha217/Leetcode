class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int profit;
        vector<vector<int>> ahead(2,vector<int> (k+1,0));
        vector<vector<int>> cur(2,vector<int> (k+1,0));
        //recurrence
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int buy =0;buy<=1;buy++)
            {
                for(int cap =1;cap<=k;cap++)
                {
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
        return ahead[1][k];
    }
};