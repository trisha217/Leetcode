class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> cur(2,0);
        vector<int> ahead(2,0);
        ahead[0] = ahead[1] = 0;
        long profit=0;
        //n days
        for(int i=n-1;i>=0;i--){
            //buy
            for(int j=0;j<2;j++){
                if(j==0){
                    int op1 = 0 + ahead[0];
                    int op2 = -prices[i] + ahead[1];
                    profit = max(op1,op2);
                }
                else{
                    int op1 = 0 + ahead[1];
                    int op2 = prices[i] + ahead[0];
                    profit = max(op1,op2);
                }
                cur[j] = profit;
                ahead = cur;
            }
        }
        return cur[0];
    }
};