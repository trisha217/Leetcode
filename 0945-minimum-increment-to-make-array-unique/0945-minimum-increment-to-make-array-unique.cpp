class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int count = nums[i - 1] - nums[i] + 1;
                nums[i] += count;
                ans += count;
            }
        }
        return ans;
    }
};