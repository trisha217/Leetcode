class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> tmp;

        helper(nums, tmp, st, 0);

        for(auto &i : st)
            ans.push_back(i);

        return ans;
    }

    void helper(vector<int> &nums, vector<int> &tmp, set<vector<int>> &st, int i)
    {
        if(i == nums.size())
        {
            if(tmp.size() >= 2)
                st.insert(tmp);

            return;
        }

        helper(nums, tmp, st, i + 1);

        if(tmp.empty() || tmp.back() <= nums[i])
        {
            tmp.push_back(nums[i]);
            helper(nums, tmp, st, i + 1);
            tmp.pop_back();    
        }
    }
};