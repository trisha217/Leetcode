class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi =1;
        for(int i=0;i<nums.size();i++){
            for(int prev =0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i] = dp[prev] + 1;
                    //inherit
                    cnt[i] = cnt[prev];
                }
                else if(nums[prev]<nums[i] && 1+dp[prev] == dp[i]){
                    //same length, so increase the count
                    cnt[i] = cnt[i] + cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int nos=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i] == maxi){
                nos = nos + cnt[i];
            }
        }
        return nos;
    }
};