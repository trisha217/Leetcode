class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        for(int i=n-1;i>=0;i--){
            res = res + (nums[i]-nums[0]);
        }
        return res;
    }
};