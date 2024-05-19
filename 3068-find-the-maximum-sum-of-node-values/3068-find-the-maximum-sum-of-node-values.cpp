class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> delta;
        for (int i = 0; i < n; i++) {
            int value = nums[i];
            delta.push_back((value^k)-value);
        }
        sort(delta.rbegin(), delta.rend());

        long long res = accumulate(begin(nums), end(nums), 0LL);
        for (int i = 0; i+1 < n; i+= 2) {
            int delta_1 = delta[i];
            int delta_2 = delta[i+1];
            if (delta_1+delta_2 > 0) {
                res += delta_1+delta_2;
            }
        }
        return res;
    }
};