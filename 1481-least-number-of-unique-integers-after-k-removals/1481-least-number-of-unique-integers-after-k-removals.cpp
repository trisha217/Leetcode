class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        for (auto num : arr) {
            um[num]++;
        }
        vector<pair<int, int>> vp;
        vp.reserve(um.size());
        int moveNum = 0;
        for (auto& it : um) {
            vp.push_back({ it.second, it.first });
        }
        sort(vp.begin(), vp.end());
        for (auto& p : vp) {
            if (k >= p.first) {
                moveNum++;
            }
            else {
                break;
            }
            k -= p.first;
        }

        return vp.size() - moveNum;
    }
};