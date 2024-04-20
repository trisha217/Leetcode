class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> cur(amount+1,0);
        //base case
        for(int i=0;i<=amount;i++){
            if(i%coins[0] == 0){
                prev[i] = i/coins[0];
            }
            else{
                prev[i] = 1e9;
            }
        }
        for(int ind=1;ind<n;ind++){
            for(int tar =0;tar<=amount;tar++){
                int nottake = 0 + prev[tar];
                int take = INT_MAX;
                if(coins[ind]<=tar){
                    take = 1 + cur[tar-coins[ind]];
                }
                cur[tar] = min(take,nottake);
            }
            prev = cur;
        }
        int ans =  prev[amount];
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};