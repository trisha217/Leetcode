class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        std::vector<int> res(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[start] * nums[start] > nums[end] * nums[end]) {
                res[i] = nums[start] * nums[start];
                start++;
            } else {
                res[i] = nums[end] * nums[end];
                end--;
            }
        }

        return res;
    }
};