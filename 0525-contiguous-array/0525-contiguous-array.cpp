class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        int sum = 0, result = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            if (prefixSum.count(sum))
                result = std::max(i - prefixSum[sum], result);
            else
                prefixSum[sum] = i;
        }
        return result;
    }
};