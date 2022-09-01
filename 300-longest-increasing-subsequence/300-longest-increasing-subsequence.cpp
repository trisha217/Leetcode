class Solution {
    public:
    //memoization
    // int f(int ind, int prev_ind, vector<int> nums, vector<vector<int>> dp, int n){
    //     if(ind == n){
    //         return 0;
    //     }
    //     if(dp[ind][prev_ind+1]!=-1){
    //         return dp[ind][prev_ind+1];
    //     }
    //     int take= 0;
    //     int not_take = 0 + f(ind+1, prev_ind, nums, dp, n);
    //     if(prev_ind == -1 || nums[ind]>nums[prev_ind]){
    //         take = 1+f(ind+1,ind,nums,dp,n);
    //     }
    //     return dp[ind][prev_ind+1] = max(take,not_take);
    // }
    int lengthOfLIS(vector<int> nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int ind = n-1; ind>=0; ind --){
            for (int prev_ind = ind-1; prev_ind >=-1; prev_ind --){
                int take= 0;
                int not_take = 0 + dp[ind+1][prev_ind +1];
                if(prev_ind == -1 || nums[ind]>nums[prev_ind]){
                    take = 1+dp[ind+1][ind+1];
                }
                dp[ind][prev_ind+1] = max(take,not_take);
            }
        }
        
        return dp[0][0];
    }
};