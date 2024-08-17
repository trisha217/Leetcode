class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = INT_MIN;
        int mini = prices[0];
        for(int i=1;i<n;i++){
            int profit = prices[i] - mini;
            maxProfit=max(profit,maxProfit);
            mini = min(prices[i],mini);
        }
        return maxProfit>0?maxProfit: 0;
    }
};

