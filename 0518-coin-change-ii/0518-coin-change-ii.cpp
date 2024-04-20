class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> cur(amount+1,0);
        //base case
        for(int i=0;i<=amount;i++){
            if(i%coins[0] == 0){
                prev[i] = 1;
            }
            else{
                prev[i] = 0;
            }
        }
        for(int ind=1;ind<n;ind++){
            for(int tar =0;tar<=amount;tar++){
                int nottake = 0 + prev[tar];
                int take = 0;
                if(coins[ind]<=tar){
                    take = cur[tar-coins[ind]];
                }
                cur[tar] = take + nottake;
            }
            prev = cur;
        }
        int ans =  prev[amount];
        return ans;
    }
};