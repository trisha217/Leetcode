class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int pre_sum = 0,res = 0;
        for(auto ele:nums)
        {
            pre_sum += ele;
            if(mp.find(pre_sum-k) != mp.end())
            {
                res = res + mp[pre_sum-k];
            }
            mp[pre_sum]++;
        }
        return res;
    }
};