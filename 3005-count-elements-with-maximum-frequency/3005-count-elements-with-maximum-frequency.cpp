class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for(int num : nums) {
            mp[num]++;
        }
        int maxFreq = 0;
        for(auto m : mp) {
            if(m.second>maxFreq) maxFreq = m.second;
        }
        for(auto m : mp) {
            if(m.second == maxFreq) ans += maxFreq;
        }
        return ans;
    }
};