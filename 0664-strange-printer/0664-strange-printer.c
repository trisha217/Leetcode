int solve(int l, int r, char *s, int dp[100][100]) {
    if (l == r) return 1;
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    int i = l + 1;
    while (i <= r && s[i] == s[l]) i++;
    int ans = 1 + solve(i, r, s, dp);

    for (int j = i; j <= r; j++) {
        if (s[j] == s[l]) {
            int temp = solve(i, j - 1, s, dp) + solve(j, r, s, dp);
            if (temp < ans) {
                ans = temp;
            }
        }
    }

    return dp[l][r] = ans;
}

int strangePrinter(char *s) {
    int n = strlen(s);
    int dp[100][100]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    return solve(0, n - 1, s, dp);
}