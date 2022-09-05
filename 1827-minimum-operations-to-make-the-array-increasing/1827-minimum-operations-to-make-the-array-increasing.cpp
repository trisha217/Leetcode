class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n ==1){
            return 0;
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<=nums[i]){
                ans+= nums[i] + 1 - nums[i+1];
                nums[i+1] = nums[i] + 1;
            }
        }
        // int flag = 0;
        // for(int i=1;i<n;i++){
        //     if(nums[i-1]==nums[i]){
        //         flag++;
        //     }
        // }
        // //cout<<flag;
        // if(flag+1 ==n){
        //     return n;
        // }
        return ans;
    }
};