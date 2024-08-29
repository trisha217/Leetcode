class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && maxInd<=i){
                break;
            }
            maxInd = max(maxInd, i + nums[i]);
        }
        if(maxInd>=nums.size()-1){
            return true;
        }
        return false;
    }
};