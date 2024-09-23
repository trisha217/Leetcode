class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> dictSet(dict.begin(), dict.end());
        int n = s.length();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1 + dp[i + 1];  // Assume the current character is extra
        
            for (int j = i; j < n; ++j) {
                string currentSubstr = s.substr(i, j - i + 1);
                
                if (dictSet.find(currentSubstr) != dictSet.end()) {
                    dp[i] = min(dp[i], dp[j + 1]);  // Update dp[i] if we find a match
                }
            }
        }
        return dp[0];  // Minimum extra characters for the whole string
    }
};