class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        int maxProfit = 0;
        int cost = 0;
        int mini = price[0];
        for(int i=0;i<n;i++){
            cost = price[i] - mini;
            maxProfit = max(cost, maxProfit);
            mini = min(mini, price[i]);
        }
        return maxProfit;
    }
};