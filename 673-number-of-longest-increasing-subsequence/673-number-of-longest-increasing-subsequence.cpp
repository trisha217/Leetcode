class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi=1;
        for(int ind=0;ind<=n-1;ind++){
            for(int prev =0;prev<=ind-1;prev++){
                if(nums[prev]<nums[ind] && dp[ind]<1+dp[prev]){
                    dp[ind] =1 +dp[prev];
                    //inherit
                    cnt[ind]=cnt[prev];
                }
                else if(nums[prev]<nums[ind] && dp[ind]==1+dp[prev]){
                    dp[ind] =1 +dp[prev];
                    //increase the count
                    cnt[ind]+=cnt[prev];
                }
            }
            if(maxi<dp[ind]){
                maxi = dp[ind];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};