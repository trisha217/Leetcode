class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        int cnt=1,res=0;
        for(int i=0;i<n;i++){
            if(nums[i]== maxi){
                res++;
                cnt = max(cnt,res);
            }
            else{
                res =0;
            }
        }
        return cnt;
    }
};