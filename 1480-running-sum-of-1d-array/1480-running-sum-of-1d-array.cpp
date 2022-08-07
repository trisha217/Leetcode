class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = nums[0];
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            sum = sum + nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};