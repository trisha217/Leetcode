class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int result = 0;
        int v[128]{};

        for (int i = 0; i < garbage.size(); ++i) {
            for (char c : garbage[i])
                result += exchange(v[c], 0) + 1;
            if (i < travel.size()) {
                v['M'] += travel[i];
                v['P'] += travel[i];
                v['G'] += travel[i];
            }
        }
        return result;
    }
};