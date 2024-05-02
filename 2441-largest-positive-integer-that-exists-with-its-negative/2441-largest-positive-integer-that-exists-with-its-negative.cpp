class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int l (0), r (nums.size() - 1);

        while (l < r) 
        {
            if (nums[l] > 0 || nums[r] < 0)
            {
                return -1;
            }
            
            if (std::abs(nums[l]) == nums[r])
            {
                return nums[r];
            }

            if (std::abs(nums[l]) > nums[r])
            {
                ++l;
            } else {
                --r;
            }

        }
        return -1;
    }
};