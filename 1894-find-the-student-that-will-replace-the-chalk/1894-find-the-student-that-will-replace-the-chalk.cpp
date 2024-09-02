class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long tot = 0;
        for (auto i: chalk) tot += i;
        int rem = k % tot;
        int res_index = 0;
        while (rem >= 0) {
            rem -= chalk[res_index];
            if (rem < 0)    break;
            else res_index++;
        }

        return res_index;
    }
};