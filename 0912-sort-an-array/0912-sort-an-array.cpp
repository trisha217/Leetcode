class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        map<int, int> mp;

        for(auto ch: nums)
        {
           mp[ch]++;
        }

        nums.clear();

        for(auto ch: mp)
        {
            nums.insert(nums.end(), ch.second, ch.first);
        }
        return nums;
    }
};