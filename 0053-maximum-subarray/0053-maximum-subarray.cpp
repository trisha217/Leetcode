class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n=nums.size();
        int ans =0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            ans = ans + nums[i];
            maxi = max(maxi,ans);
            if(ans<0){
                ans =0;
            }
        }
        return maxi;
    }
};