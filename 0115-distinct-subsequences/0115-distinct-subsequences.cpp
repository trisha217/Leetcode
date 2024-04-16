class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        int MOD = 1e9 + 7; // Define a modulo value
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0)); // Changed int to long long
        for (int ind1 = 0; ind1 <= n; ind1++) {
            dp[ind1][0] = 1;
        }
        for (int ind2 = 1; ind2 <= m; ind2++) {
            dp[0][ind2] = 0;
        }
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s[ind1 - 1] == t[ind2 - 1]) {
                    dp[ind1][ind2] = (dp[ind1 - 1][ind2 - 1] + dp[ind1 - 1][ind2])% MOD;
                } else {
                    dp[ind1][ind2] = dp[ind1 - 1][ind2];
                }
            }
        }
        return dp[n][m];
    }
};