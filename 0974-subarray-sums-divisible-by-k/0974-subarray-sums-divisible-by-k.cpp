class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix = 0;
        int ans = 0;
        map<int, int> m;
        m[0] = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            prefix += nums[i];
            int rem = prefix%k;
            if(rem < 0)
            {
                rem += k;   
            }
            if(m[rem] !=0)
            {
                ans += m[rem];
            }
            m[rem]++;
        }
        return ans;
    }
};