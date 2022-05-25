class Solution {
    public int lengthOfLIS(int[] nums) {
        
        int n = nums.length;
        if(n==1){
            return 1;
        }
        int omax =0;
        int[] dp = new int[n];
        dp[0] = 1;
        for(int i=1;i<n;i++){
            int max =0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]>max){
                        max = dp[j];
                    }
                }
            }
            dp[i] = max +1;
            if(dp[i]>omax){
                omax = dp[i];
            }
        }
        return omax;
    }
}