class Solution {
public:
    int minDifference(vector<int>& nums) {

        sort(nums.begin() , nums.end());
        int n = nums.size();

        if(n<=4) return 0;
 
        int min_1 = min(nums[n-1]-nums[3], nums[n-4]-nums[0]);
        int min_2 = min(nums[n-3]-nums[1], nums[n-2]-nums[2]);

        return min(min_1,min_2);
    }
};