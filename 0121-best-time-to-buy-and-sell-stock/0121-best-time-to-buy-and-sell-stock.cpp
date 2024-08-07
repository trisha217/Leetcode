class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0;
        int mini= INT_MAX;
        int n = prices.size();
        for(int i=0;i<n;i++){
            mini = min(prices[i],mini);
            int profit = prices[i]-mini;
            maxpro = max(profit,maxpro);
        }
        return maxpro<0?0:maxpro;
    }
};

