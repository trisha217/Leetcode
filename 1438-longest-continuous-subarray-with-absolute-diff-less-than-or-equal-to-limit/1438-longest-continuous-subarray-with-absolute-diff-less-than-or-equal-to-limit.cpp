class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> mp;
        int sz = 1, n = nums.size(), res = 1;
        mp[nums[0]] = 1;
        bool prevSatisfy = true;
        for (int i = 1; i < n; ++ i) {
            ++ mp[nums[i]];
            if (prevSatisfy) {
                ++ sz;
                if (mp.rbegin()->first - mp.begin()->first <= limit) res = sz;
                else prevSatisfy = false;
            } else {
                -- mp[nums[i - sz]];
                if (mp[nums[i - sz]] == 0) mp.erase(nums[i - sz]);
                if (mp.rbegin()->first - mp.begin()->first <= limit) {
                    res = sz;
                    prevSatisfy = true;
                }
            }
        }
        return res;
    }
};