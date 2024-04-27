class Solution {
public:
    int solve(string ring, string key, int ptr, int idx, int n, int m, vector<vector<int>> &dp){
        if(idx>=m) return 0;
        
        if(dp[idx][ptr]!=-1) return dp[idx][ptr];
        int steps = 1e9;
        for(int i=0; i<n; i++){
            if(ring[i]==key[idx]){
                steps = min(steps, min(abs(i-ptr), n-abs(i-ptr))+1 + solve(ring, key, i, idx+1, n, m, dp));
                
            }
        }

        return dp[idx][ptr] = steps;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(ring, key, 0, 0, n, m, dp);
    }
};