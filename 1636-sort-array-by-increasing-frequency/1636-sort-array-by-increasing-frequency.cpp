bool sortal(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second==b.second) return a.first>b.first;
    else return a.second < b.second;
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        vector<pair<int, int>> hash;
        for (auto it : mp) {
            hash.push_back(make_pair(it.first,it.second));
        }
        sort(hash.begin(), hash.end(), sortal);
        vector<int> ans;

        for (auto it : hash) {
            while (it.second != 0) {
                ans.push_back(it.first);
                it.second=it.second-1;
            }
        }
        return ans;
    }
};