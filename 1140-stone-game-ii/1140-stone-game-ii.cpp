class Solution {
public:
    int solve(int i, int m, vector<int>& piles, int turn, vector<vector<vector<int>>> &dp) {
        if (i >= piles.size())
            return 0;

        if(dp[i][m][turn] != -1) return dp[i][m][turn];
        int sum = 0;
        int ans = (turn == 1) ? INT_MIN : INT_MAX;

        for (int j = i; j < min(i + 2 * m, (int)piles.size()); j++) {
            sum += piles[j];
            if (turn == 1)
                ans = max(ans, sum + solve(j + 1, max(m, j - i + 1), piles, 0, dp));
            else
                ans = min(ans, solve(j + 1, max(m, j - i + 1), piles, 1, dp));
        }

        return dp[i][m][turn] = ans;
    }
    int stoneGameII(vector<int>& piles) { 
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solve(0, 1, piles, 1, dp); 
    }
};