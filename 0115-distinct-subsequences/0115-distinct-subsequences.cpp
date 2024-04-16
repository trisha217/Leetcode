class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        int MOD = 1e9 + 7; // Define a modulo value
        vector<int> prev(m + 1, 0); 
        vector<int> cur(m + 1, 0); 
        prev[0]=cur[0]=1;
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s[ind1 - 1] == t[ind2 - 1]) {
                    cur[ind2] = (prev[ind2 - 1] + prev[ind2])% MOD;
                } else {
                    cur[ind2] = prev[ind2];
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};