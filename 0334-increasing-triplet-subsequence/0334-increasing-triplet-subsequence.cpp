class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int k=INT_MAX, j=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=k){
                k = nums[i];
            }
            else if(nums[i]<=j){
                j = nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};