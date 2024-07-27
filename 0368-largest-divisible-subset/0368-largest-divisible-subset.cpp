class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        int maxi=1,last_index=0;
        for(int i = 0;i<n;i++){
            hash[i]=i;
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(maxi<dp[i]){
                maxi = dp[i];
                last_index = i;
            }
        }
        vector<int> lis(maxi);
        lis[0] = nums[last_index];
        int i=1;
        while(hash[last_index] != last_index){
            last_index = hash[last_index];
            lis[i] = nums[last_index];
            i++;
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};