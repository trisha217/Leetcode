class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0,r=0,presum=0,cnt1=0,cnt2=0;
        if(goal < 0){
            return 0;
        }
        while(r<nums.size()){
            presum = presum + nums[r];
            while(presum > goal){
                presum = presum - nums[l];
                l++;
            }
            cnt1 = cnt1 + (r - l + 1);
            r++;
        }
        l=0,r=0,presum=0;
        goal = goal -1;
        if(goal < 0){
            return cnt1;
        }
        while(r<nums.size()){
            presum = presum + nums[r];
            while(presum > goal){
                presum = presum - nums[l];
                l++;
            }
            cnt2 = cnt2 + (r - l + 1);
            r++;
        }
        return cnt1-cnt2;
    }
};